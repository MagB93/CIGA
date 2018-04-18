#ifndef VECTOR_WRAPPER_H
#define VECTOR_WRAPPER_H

#include "base.h"
#include <cmath>
#include <vector>

namespace base_n
{
  template< typename T >
  struct vector_t
  {
    std::vector< T > _vec;

    vector_t< T > ()
    {
      _vec = std::vector< T >();
    }

    vector_t< T >( const size_t &size )
    {
      _vec = std::vector< T > ( size );
    };

    const size_t size() const
    {
      return _vec.size();
    };

    vector_t< T > ( const vector_t< T > &copy )
    {
      _vec = copy._vec;
    };

    T & operator[] ( const size_t &index ) const
    {
      return _vec[ index ];
    };

    T & operator[] ( const size_t &index )
    {
      return _vec[ index ];
    };

    vector_t< T > & operator= ( const vector_t< T > &other )
    {
      // if( this != other )
      // {
        _vec = other;
      // }
      return *this;
    };

    friend std::ostream& operator<< ( std::ostream &os,
                                      vector_t< T > &vector )
    {
      for( size_t i = 0; i < vector.size(); ++i )
        os << vector[ i ];

      return os;
    };

    vector_t< T > ads( const vector_t< T > &vector )
    {
      vector_t< T > absVector( vector );

      for( size_t i = 0; i < vector.size(); ++i )
      {
        absVector[ i ] = std::abs( absVector[ i ] );
      }

      return absVector;

    };

  };


}


#endif
