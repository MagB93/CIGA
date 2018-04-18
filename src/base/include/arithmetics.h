//Falls pragma once auf ihrem System nicht geht, nutzen Sie statt dessen:
#ifndef arithmetics_H
#define arithmetics_H

#include "vector_wrapper.h"
#include "full_matrix.h"

#include <stdexcept>

namespace base_n
{
  template< typename T  >
  vector_t< T > const operator*( fullMatrix_t< T > const & A,
                                 vector_t< T > const & b)
  {
    if ( A._dim != b.size() )
    {
      throw std::invalid_argument( "Matrix and Vector must have the same dimension." );
    }
    vector_t< T > returnVec( b.size() );

    for( size_t i = 0; i < A._dim; ++i )
    {
      for( size_t j = 0; i < A._dim; ++j )
      {
        c[i] += returnVec.getElement( i, j ) * b[ j ];
      }
    }

    return returnVec;
      
  };
  
  fullMatrix_t< T > const operator*( fullMatrix_t< T > const & mat,
                                     T const & scal )
  {
    fullMatrix_t< T > res( mat._dim );

    for( size_t i = 0; i < A._dim; ++i )
    {
      for( size_t j = 0; i < A._dim; ++j )
      {
        c[i] += returnVec.getElement( i, j ) * scal;
      }
    }
  };

  template< typename T >
  fullMatrix_t< T > const operator*( T const & scal,
                                     fullMatrix_t< T > const & mat)
  {
    return mat * scal;
  };

  template< typename T >
  vector_t< T > const operator*( vector_t< T > const& vec,
                                 T const& scal)
  {
    vector< T > returnVec( vec.size() );

    for( size_t i = 0; i < vec.size(); ++i )
      c[i] = vec[ i ] * scal;

    return returnVec;

  };

  template< typename T >
  vector_t< T > const operator*( T const& scal,
                                 vector< T > const & vec)
  {
    return vec * scal;
  };

  template< typename T >
  vector_t< T > const operator+( vector_t< T > const & a,
                                 vector_t< T > const & b)
  {
    if ( a.size() != b.size() )
    {
      throw std::invalid_argument( "Both vectors must have the same dimension." );
    }
    vector_t< T > returnVec( a.size() );

    for( size_t i = 0; i < a.size(); ++i )
    {
      returnVec[ i ] = a[ i ] + b[ i ];
    }

    return returnVec;
  };

  template< typename T >
  vector_t< T > const operator-( vector_t< T > const & a,
                                 vector_t< T > const & b)
  {
    if ( a.size() != b.size() )
    {
      throw std::invalid_argument( "Both vectors must have the same dimension." );
    }
    vector_t< T > returnVec( a.size() );

    for( size_t i = 0; i < a.size(); ++i )
    {
      returnVec[ i ] = a[ i ] - b[ i ];
    }

    return returnVec;
  };
  
  template< typename T >
  T const operator*( vector_t< T > const & a,
                     vector_t< T > const & b)
  {
    if ( a.size() != b.size() )
    {
      throw std::invalid_argument( "Both vectors must have the same dimension." );
    }
    vector_t< T > returnVec( a.size() );

    for( size_t i = 0; i < a.size(); ++i )
    {
      returnVec[ i ] = a[ i ] * b[ i ];
    }

    return returnVec;
  };

}

#endif
