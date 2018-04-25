#ifndef BASE_H
#define BASE_H

#include <omp.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>

namespace base_n
{
  /*!
    \brief Ein Functor für die Erzeugung von Indizes.

    This basic functor just returns 0, all children of this one have to
    implement the () operator 
  */
  struct indexFunctor_t
  {
    size_t operator()( const size_t & i );
  };
};



#endif 
