cmake_minimum_required(VERSION 3.5.0)
project(leetcode_cpp VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

foreach(name
  type_traits
  nullptr_t
  forward
  atomics
  shared_mutex
  move_exceptions
  spinlock
  condition_variable
  lambdas
  ranges
  template_overload
  auto
  decltype
  rvo
  copy_elision
  constexpr
  variadic
  iterators
  concepts
  adl
  padding_alignment
  algorithms
  containers
  oop_err_1
  oop_late_binding
  oop_call_base_class_method
  friend_function
  operators
  statics
  asm
  oop_refactoring
  fibo_constexpr
  fibo_variadic
)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} PRIVATE)
  set_target_properties(${name}
    PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS off
    )
  add_test(
    NAME ${name}
    COMMAND $<TARGET_FILE:${name}>)
endforeach()

include(CPack)
