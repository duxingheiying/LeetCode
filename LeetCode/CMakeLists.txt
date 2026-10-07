
add_executable(LengthOfLongestSubstring "LengthOfLongestSubstring.cpp")
add_executable(TwoNumSum "TwoNumSum.cpp")
add_executable(LongestPalindrome "LongestPalindrome.cpp")
add_executable(gNucleus "gNucleus.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LengthOfLongestSubstring PROPERTY CXX_STANDARD 20)
  set_property(TARGET TwoNumSum PROPERTY CXX_STANDARD 20)
  set_property(TARGET LongestPalindrome PROPERTY CXX_STANDARD 20)
endif()