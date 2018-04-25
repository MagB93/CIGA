#include "gtest/gtest.h"
#include "base/full_matrix.h"
#include "base/vector_wrapper.h"

struct ArithmeticsFullMatrix_f : public ::testing::Test
{
  virtual void SetUp()
  {
    _matrix = fullMatrix_t< double >( 4 );
    _vector = vector_t< double >( 4 );
    _vector2 = vector_t< double > ( 4 );

    // Setze ein paar Werte für die Matrizen
    for( size_t i = 0; i < 4; ++i )
    {
      for( size_t j = 0; j < 4; ++j )
      {
        _matrix( i, j ) = j + 1;
      }
      _vector[ i ] = i + 1;
    }
  }

  fullMatrix_t< double > _matrix;
  vector_t< double > _vector;
  vector_t< double > _vector2;

};

TEST_F( ArithmeticsFullMatrix_f, elementwiseMatrixMul)
{
  const auto matrix2 = _matrix * 2.;

  fullMatrix_t< double > referenceMatrix2( _matrix.size() );
  for( size_t i = 0; i < 4; ++i )
  {
    for( size_t j = 0; j < 4; ++j )
    {
      referenceMatrix2( i, j ) = ( j + 1 ) * 2;
    }
  }

  for ( size_t i = 0; i < 4; ++i )
  {
    for ( size_t j = 0; j < 4; ++j )
    {
      EXPECT_EQ( matrix2( i, j ), referenceMatrix2( i, j ) );
    }
  }
};

TEST_F( ArithmeticsFullMatrix_f, elementwiseVectorMul )
{
  const auto vector2 = _vector * 2;

  vector_t< double > referenceVec2( _vector.size() );

  for ( size_t i = 0; i < 4; ++i )
  {
    EXPECT_EQ( vector2[ i ], referenceVec2[ i ] );
  }

};

TEST_F( ArithmeticsFullMatrix_f, scalarProduct )
{
  const auto result = _matrix * _vector;

  for ( size_t i = 0; i < 4; ++i )
  {
    EXPECT_EQ( result[ i ], 30. );
  }
}

}





