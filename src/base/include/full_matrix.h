#ifndef FULL_MATRIX_H
#define FULL_MATRIX_H

#include "vector_wrapper.h"

namespace base_n
{
  template< typename T >
  struct fullMatrix_t
  {
    size_t _dim;
    size_t _size;
    vector_t< T > _data;

    inline const size_t index( const size_t i, const size_t j ) const
    {
      return i * _dim + j;
    };

    fullMatrix_t< T >( const size_t &dim = 1 )
    {
      _dim = dim;
      _size = dim * dim;
      _data = vector_t< T > ( _size );
    };

    fullMatrix_t< T >( const fullMatrix_t< T > &copy )
    {
      _dim = copy._dim;
      _size = copy._size;
      _data = copy._data;
    };

    T & getElement( const size_t i, const size_t j ) const
    {
      const size_t wantedIndex = index( i, j );
      return _data[ wantedIndex ];
    };

    T & getElement( const size_t i, const size_t j )
    {
      const size_t wantedIndex = index( i, j );
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
          os << matrix.getElement( i, j ) << " ";

        os << std::endl;
      }
    };

  };
}


#endif
