#ifndef FULL_MATRIX_H

#define FULL_MATRIX_H

#include "base/vector_wrapper.h"
#include <armadillo>

namespace base_n
{
  struct fullMatrixIndexFunctor_t : public indexFunctor_t
  {
    //! Number of columns / rows
    size_t _dim;

    fullMatrixIndexFunctor_t( const size_t &dim = 0)
    {
      _dim = dim;
    }

    inline const size_t index( const size_t i,
                               const size_t j ) const
    {
      return i * _dim + j;
    };


    const size_t operator()( const size_t &i,
                             const size_t &j ) const
    {
      return index( i, j );
    }
  };

  /*!
    \brief Matrix implementation for a square-matrix
   */
  template< typename T >
  struct fullMatrix_t
  {
    //! The functor for indexing the matrix
    fullMatrixIndexFunctor_t _indexer;
    //! number of elements = _dim ^ 2
    size_t _size;
    //! Underlying data
    vector_t< T > _data;

    fullMatrix_t< T >( const size_t &dim = 1 )
    {
      _indexer = fullMatrixIndexFunctor_t( dim );
      _size = dim * dim;
      _data = vector_t< T > ( _size );
    };

    fullMatrix_t< T >( const fullMatrix_t< T > &copy )
    {
      _indexer = copy._indexer;
      _size = copy._size;
      _data = copy._data;
    };

    size_t size() const
    {
      return _size;
    }

    size_t dim() const
    {
      return _indexer._dim;
    }

    const T & operator()( const size_t i, const size_t j ) const
    {
      const size_t wantedIndex = _indexer( i, j );
      return _data[ wantedIndex ];
    };

    T & operator()( const size_t i, const size_t j )
    {
      const size_t wantedIndex = _indexer( i, j );
      return _data[ wantedIndex ];
    };

    friend std::ostream& operator<< ( std::ostream &os,
                                      fullMatrix_t< T > &matrix )
    {
      os << "Matrix Dimension: " << matrix._dim << std::endl;
      os << "Matrix Size: " << matrix._size << std::endl;
      os << "Matrix Elements: \n";

      for( size_t i = 0; i < matrix._dim; ++i )
      {
        for( size_t j = 0; j < matrix._dim; ++j )
          os << matrix( i, j ) << " ";

        os << std::endl;
      }
    };

    /*!
     \brief Scalar-Product of a matrix with a vector
    */
   vector_t< T > const operator*( vector_t< T > const & b)
   {
     if ( this->dim() != b.size() )
     {
       throw std::invalid_argument( "Matrix and Vector must have the same dimension." );
     }
     vector_t< T > returnVec( b.size() );

     for( size_t i = 0; i < this->dim(); ++i )
     {
       for( size_t j = 0; i < this->dim(); ++j )
       {
         returnVec[ i ] += this->operator()( i, j ) * b[ j ];
       }
     }

     return returnVec;

   };

   /*!
     \brief Elementwise multiplication of a matrix with a scalar
    */
   fullMatrix_t< T > const operator*( T const & scal )
   {
     fullMatrix_t< T > returnMatrix( this->dim() );

     for( size_t i = 0; i < this->dim(); ++i )
     {
       for( size_t j = 0; i < this->dim(); ++j )
       {
         returnMatrix( i, j ) = this->operator()( i, j ) * scal;
       }
     }

     return returnMatrix;
   };

  };


  template< typename T >
  base_n::fullMatrix_t< T > eyeMatrix( const size_t &dim )
  {
    fullMatrix_t< T > eyeMatrix( dim );

    for( size_t i = 0; i < dim; ++i )
    {
      eyeMatrix( i, i ) = static_cast< T > ( 1 );
    }

    return eyeMatrix;
  };

#endif
