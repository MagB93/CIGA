#include "Arithmetics.h"
#include <iostream>
#include <stdexcept>
/*
 * Matrix - Vektor Multiplikation
 */
Vector const operator*(FullMatrix const& A, Vector const& b)
{
  if( A.dim() != b.dim() )
  {
    throw std::invalid_argument("Matrix and Vector must have the same dimension.");
  }
  Vector c(b.dim());
  
  for( int i = 0 ; i < A.dim() ; i++ )
  {
    c(i) = 0;
    for( int j = 0 ; j < A.dim() ; j++ )
    {
      c(i) += A(i,j) * b(j);
    }
  }
  return c;
}
/*
 * Matrix - Skalar Multiplikation
 */
FullMatrix const operator*(FullMatrix const& mat, double const& scal)
{
  FullMatrix res(mat.dim());
  for( int i = 0 ; i < mat.dim() ; i++ )
  {
    for( int j = 0 ; j < mat.dim() ; j++ )
    {
      res(i,j) = scal * mat(i,j); 
    }
  }
  return res;
}
/*
 * Skalar - Matrix Multiplikation
 */
FullMatrix const operator*(double const& scal, FullMatrix const& mat)
{
  return mat * scal; 
}

/**
 * (elementweise) Vektor - Vektor Addition
 */
Vector const operator+(Vector const& a, Vector const& b)
{
  if( a.dim() != b.dim() )
  {
    throw std::invalid_argument("Both Vectors must have the same dimension.");
  }
  Vector c(a.dim());
  for( int i = 0 ; i < a.dim() ; i++ )
  {
    c(i) = a(i) + b(i); 
  }
  return c;
}
/*
 * (elementweise) Vektor - Vektor Subtraktion
 */
Vector const operator-(Vector const& a, Vector const& b)
{
  if( a.dim() != b.dim() )
  {
    throw std::invalid_argument("Both Vectors must have the same dimension.");
  }
  Vector c(a.dim());
  for( int i = 0 ; i < a.dim() ; i++ )
  {
    c(i) = a(i) - b(i); 
  }
  return c;
}
/*
 * Vektor - Vektor Multiplikation 
 * (Skalarprodukt, inneres Produkt)
 * a^T*b
 */
double const operator*(Vector const& a, Vector const& b)
{
  if( a.dim() != b.dim() )
  {
    throw std::invalid_argument("Both Vectors must have the same dimension.");
  }
  double res = 0.0;
  for( int i = 0 ; i < a.dim() ; i++ )
  {
    res += a(i) * b(i); 
  }
  return res;
}
/*
 * Vektor - Skalar Multiplikation
 */
Vector const operator*(Vector const& vec, double const& scal)
{ 
  Vector res(vec.dim());
  for( int i = 0 ; i < vec.dim() ; i++ )
  {
    res(i) = scal * vec(i); 
  }
  return res;
}
/*
 * Skalar - Vektor Multiplikation
 */
Vector const operator*(double const& scal, Vector const& vec)
{
  return vec * scal; 
}