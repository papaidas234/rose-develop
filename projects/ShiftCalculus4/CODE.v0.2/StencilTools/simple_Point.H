#ifndef POINT_H
#define POINT_H
#include "SPACE.H"
// #include <assert.h>
// #include <iostream>
// #include <array>

#include "vector_lite.h"

using namespace std;

///A point in space
/**
  An Integer valued point in space of arbitrary dimension. May also be used to represent a vector with integer components.
*/

class Point
{
public:
  /// Default Constructor
  inline Point();
  /// Construct a Point using an int array
  inline Point(const int a_tuple[DIM]);
  /// Construct a Point using an int array
  inline Point(const array<int,DIM> a_tuple);
  /// Copy Constructor
  Point(const Point& a_pt);

  ///Definition of "<" operator on Points. Returns true if this* is "less than" *a_rhs
  /** 
      This is just an ordering. It is used to add Points to maps etc. Don't use it to actually compare Points. 
  */
  inline bool operator<(const Point& a_rhs) const;

  /// Componentwise addition of two Points. 
  inline Point operator+(const Point& a_rhsPoint) const;

  ///Componetwise subtraction of two Points. 
  inline Point operator-(const Point& a_rhsPoint) const;

  ///Componentwise division of a Point by an Integer.
  /**
    Quotients are rounded down. Division of any component by 0 yields an error. 
  */
  inline Point operator/(int a_nref) const;

  ///Componentwise division of a Point by another Point.
  /**
      Quotients are rounded down. Division of any component by 0 yields an error. 
  */
  inline Point operator/(const Point& a_pt) const;

  ///Componentwise multiplication of a Point by an Integer
  Point operator*(int a_nref) const;

  /// Componentwise multiplication between two Points.
  inline Point operator*(const Point& a_pt) const;

  /// Multiplication of two Points in place.
  inline void operator*=(const Point& a_pt);

  /// Addition of two Points in place.
  inline void operator+=(const Point& a_pt);

  /// Subtraction of two Points in place.
  inline void operator-=(const Point& a_pt);

  /// Division of two Points in place.
  /**
      Quotients are rounded down. Division of any component by 0 yields an error. 
  */
  inline void operator/=(const Point& a_pt);

  /// Multiplication in place by an Integer.
  inline void operator*=(int a_n);

  /// Addition in place by an Integer.
  inline void operator+=(int a_n);

  /// Subtraction in place by an Integer.
  inline void operator-=(int a_n);

  /// Division in place by an Integer.
  /**
      Quotients are rounded down. Division of any component by 0 yields an error. 
  */
  inline void operator/=(int a_n);

  /// Equality between two Points.
  /**
    Returns true if *this[\f$k\f$] == *a_pt[\f$k\f$] \f$\forall\,k\,\in\,[0,DIM)\f$
  */
  inline bool operator==(const Point& a_pt) const;

  /// Inequality between two Points.
  /**
    Returns false if *this == *a_pt.
  */
  inline bool operator!=(const Point& a_pt) const;

  /// Get component of *this corresponding to a_index.
  /**
    For use with constant Points
  */
  inline const int&  operator[](const int& a_index) const;

  /// Get component of *this corresponding to a_index.
  int&  operator[](const int& a_index);

  ///Print out the contents of a Point.
  /**
    Output is formatted: (p1,p2,...)
  */
  void print() const;

  ///Print out the contents of a Point.
  /**
    Output is formatted: p1 p2 p3 ...
  */
  inline void print2() const;

private:
#if 0
  int m_tuple[DIM]; ///<Integer coordinates of the Point
#endif
};

/// Returns a Point representing the idir-directional basis vector of dimension DIM
/**
  Output is a unit vector \f$\mathbf{v}: \mathbf{v}[k] = \delta_{idir}^k\f$. This function is identical to getUnitv()
*/
inline Point getBasisV(int idir);

/// Returns a Point of dimension DIM with all entries equal to 0. 
Point getZeros();

/// Returns a Point of dimension DIM with all entries equal to 1. 
Point getOnes();

/// Returns a Point representing the idir-directional basis vector of dimension DIM. Identical to getBasisV()
/**
  Output is a unit vector \f$\mathbf{v}: \mathbf{v}[k] = \delta_{idir}^k\f$. This function is identical to getBasisV()
*/
Point getUnitv(int a_dir);

// inline ostream& operator <<(ostream& a_os, const Point& a_pt);

// #include "PointImplem.H"

#endif
