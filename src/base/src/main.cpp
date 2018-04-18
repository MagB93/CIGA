#include "vector_wrapper.h"
#include "full_matrix.h"

int main()
{
  base_n::vector_t< int32_t > vector( 2 );
  vector[ 0 ] = 1;
  vector[ 1 ] = 2;

  std::cout << vector;

  base_n::fullMatrix_t< int32_t > fullMat( 2 );
  fullMat.getElement( 1, 1 ) = 1;
  fullMat.getElement( 1, 2 ) = 2;
  fullMat.getElement( 2, 1) = 3;
  fullMat.getElement( 2, 2 ) = 4;

  std::cout << fullMat;


  return 0;
}
