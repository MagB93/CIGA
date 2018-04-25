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

    const T & operator[] ( const size_t &index ) const
    {
      return _vec[ index ];
    };

    T & operator[] ( const size_t &index )
    {
      return _vec[ index ];
    };

    vector_t< T > & operator= ( const vector_t< T > &other )
    {
      _vec = other._vec;
      return *this;
    };

    friend std::ostream& operator<< ( std::ostream &os,
                                      vector_t< T > &vector )
    {
      for( size_t i = 0; i < vector.size(); ++i )
        os << vector[ i ];

      return os;
    };

   /*!
     \brief Elementwise substraction of two vectors
    */
   vector_t< T > const operator-( vector_t< T > const & a ) const
   {
     if ( this->size() != a.size() )
     {
       throw std::invalid_argument( "Both vectors must have the same dimension." );
     }
     vector_t< T > returnVec( this->size() );

     for( size_t i = 0; i < this->size(); ++i )
     {
       returnVec[ i ] = this[ i ] - a[ i ];
     }

     return returnVec;
   };

   T const operator*( vector_t< T > const & a ) const
   {
     if ( this->size() != a.size() )
     {
       throw std::invalid_argument( "Both vectors must have the same dimension." );
     }
     vector_t< T > returnVec( this->size() );

     for( size_t i = 0; i < this->size(); ++i )
     {
       returnVec[ i ] = this[ i ] * a[ i ];
     }

     return returnVec;
   };

   /*!
     \brief Elementwise multiplication of a vector with a scalar
    */
   vector_t< T > const operator*( T const& scal) const
   {
     vector_t< T > returnVec( this->size() );

     for( size_t i = 0; i < this->size(); ++i )
       returnVec[ i ] = this->operator[]( i ) * scal;

     return returnVec;

   };

   /*!
     \brief Elementwise additon of two vectors
    */
   vector_t< T > const operator+( vector_t< T > const & a )
   {
     if ( this->size() != a.size() )
     {
       throw std::invalid_argument( "Both vectors must have the same dimension." );
     }
     vector_t< T > returnVec( this->size() );

     for( size_t i = 0; i < this->size(); ++i )
     {
       returnVec[ i ] = this[ i ] + a[ i ];
     }

     return returnVec;
   };

  };

  template< typename T >
  vector_t< T > abs( const vector_t< T > &vector )
  {
    vector_t< T > absVector( vector );

    for( size_t i = 0; i < vector.size(); ++i )
    {
       absVector[ i ] = std::abs( absVector[ i ] );
    }

    return absVector;
  };

}


#endif
