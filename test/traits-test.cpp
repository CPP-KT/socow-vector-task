#include "socow-vector.h"
#include "test-utils.h"

#include <catch2/catch_test_macros.hpp>

#include <iterator>
#include <ranges>
#include <type_traits>

namespace ct::test {

TEST_CASE("Member types") {
  STATIC_REQUIRE(std::is_same_v<SocowVector<Element, 3>::ValueType, Element>);
  STATIC_REQUIRE(std::is_same_v<SocowVector<Element, 3>::Reference, Element&>);
  STATIC_REQUIRE(std::is_same_v<SocowVector<Element, 3>::ConstReference, const Element&>);
  STATIC_REQUIRE(std::is_same_v<SocowVector<Element, 3>::Pointer, Element*>);
  STATIC_REQUIRE(std::is_same_v<SocowVector<Element, 3>::ConstPointer, const Element*>);
  STATIC_REQUIRE(std::is_same_v<SocowVector<Element, 3>::Iterator, Element*>);
  STATIC_REQUIRE(std::is_same_v<SocowVector<Element, 3>::ConstIterator, const Element*>);
}

TEST_CASE("Vector is contiguous") {
  STATIC_REQUIRE(std::contiguous_iterator<SocowVector<Element, 3>::Iterator>);
  STATIC_REQUIRE(std::contiguous_iterator<SocowVector<Element, 3>::ConstIterator>);

  STATIC_REQUIRE(std::ranges::contiguous_range<SocowVector<Element, 3>>);
}

} // namespace ct::test
