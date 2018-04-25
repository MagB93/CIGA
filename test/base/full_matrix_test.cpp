
#include "gtest/gtest.h"
#include <cstdint>
#include "base/full_matrix.h"

struct MatrixOperations_f : public ::testing::Test
{
  virtual void SetUp()
  {
    // Creates a 4 x 4 Matrix
    _matrix = base_n::fullMatrix_t< double >( 4 );
  }

  base_n::fullMatrix_t< double > _matrix;

};

// We want to test wether one can modify a matrix
TEST_F( MatrixOperations_f, referenceOperator )
{
  _matrix = base_n::eyeMatrix< double >( 4 );

  for( size_t i = 0; i < 4; ++i )
    EXPECT_EQ( _matrix( i, i ), 1. );

  _matrix( 0, 0 ) = 2.;

  EXPECT_EQ( _matrix( 0, 0 ), 2. );
  for( size_t i = 1; i < 4; ++i )
    EXPECT_EQ( _matrix( i, i ), 1. );
  
}
}

