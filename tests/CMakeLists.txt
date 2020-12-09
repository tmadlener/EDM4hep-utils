add_executable(unittests
  test_kinematics.cpp
  )

target_link_libraries(unittests EDM4HEP::edm4hep kinematics Catch2::Catch2 Catch2::Catch2WithMain)

catch_discover_tests(unittests)
