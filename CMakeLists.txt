cmake_minimum_required(VERSION 3.5.0)
project(leetcode_cpp VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

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
  exceptions_err1
  exception_ptr
  exception_uncaught
  allocators
  overloads
  requires
  sockets
  geeks
  ctor_dtor
  metaprogramming
  dsa
  bluetooth_linux
  pcap_linux
  upnp_linux
  exception_empty
)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} PRIVATE Threads::Threads)
  if (${name} STREQUAL "bluetooth_linux")
    target_link_libraries(${name} PRIVATE "bluetooth")
  elseif (${name} STREQUAL "pcap_linux")
    target_link_libraries(${name} PRIVATE "pcap")
  elseif (${name} STREQUAL "upnp_linux")
    target_link_libraries(${name} PRIVATE "upnp")
  endif()
  set_target_properties(${name}
    PROPERTIES
    CXX_STANDARD 23
    CXX_EXTENSIONS off
    )
  add_test(
    NAME ${name}
    COMMAND $<TARGET_FILE:${name}>)
endforeach()

include(CPack)
