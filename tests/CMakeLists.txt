#============================================================================#

add_executable(TestAbstracts)

target_sources(TestAbstracts
  PRIVATE
    TestAbstracts.cpp
  )

target_link_libraries(TestAbstracts
  PRIVATE
    ShishGL)

#============================================================================#

