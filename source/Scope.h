#include <string>
#include <forward_list>
#include <unordered_map>

#ifndef SCOPE
#define SCOPE

namespace lyrics
{
	using std::u16string;
	using std::forward_list;
	using std::unordered_map;

	class Scope
	{
	public:
		Scope( Scope * const parent ) : mParent( parent ), mLastChild( mChildren.cbefore_begin() )
		{
			if ( parent )
			{
				parent->AddChlid( this );
			}
		}

		~Scope()
		{
			for ( auto i : mChildren )
			{
				delete i;
			}
		}

		const Scope *GetParent() const
		{
			return mParent;
		}

		void AddChlid( Scope * const child )
		{
			mLastChild = mChildren.insert_after( mLastChild, child );
		}

		bool IsPublicExist( const u16string * const identifier ) const
		{
			auto iterator = mEntities.find( *identifier );

			if ( iterator != mEntities.cend() && iterator->second == true && iterator->first == *identifier )
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool IsExist( const u16string * const identifier ) const
		{
			auto iterator = mEntities.find( *identifier );

			if ( iterator != mEntities.cend() && iterator->first == *identifier )
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		void AddPublic( const u16string * const entity )
		{
			mEntities[*entity] = true;
		}

		void AddPrivate( const u16string * const entity )
		{
			mEntities[*entity] = false;
		}

	private:
		const Scope * const mParent;
		forward_list<Scope *> mChildren;
		forward_list<Scope *>::const_iterator mLastChild;
		unordered_map<u16string, bool> mEntities;
	};
}

#endif
