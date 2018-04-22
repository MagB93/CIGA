#include "gtest/gtest.h"
#include "base/vector_wrapper.h"

struct VectorOperations_f : public ::testing::Test
{
  virtual void SetUp()
  {
    _vector = base_n::vector_t< int32_t >( 4 );
  }

  base_n::vector_t< int32_t > _vector;
};

TEST_F( VectorOperations_f, size )
{
  EXPECT_EQ( _vector.size(), 4 );
}

TEST_F( VectorOperations_f, referenceOperator )
{
  _vector[ 0 ] = 1;
  _vector[ 1 ] = 2;
  _vector[ 2 ] = 3;
  _vector[ 3 ] = 4;

  for( size_t i = 0; i < 4; i++ )
    EXPECT_EQ( _vector[ i ], i + 1 );
}

TEST_F( VectorOperations_f, abs )
{
  _vector[ 0 ] = 1;
  _vector[ 1 ] = -2;
  _vector[ 2 ] = -3;
  _vector[ 3 ] = -4;

  const base_n::vector_t< int32_t > absVector = base_n::abs( _vector );

  for( size_t i = 0; i < 4; i++ )
    EXPECT_EQ( absVector[ i ], i + 1 );
}


