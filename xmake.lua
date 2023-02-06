add_rules("mode.debug", "mode.release")

set_project("leetcode")

set_languages("c++17")

add_requires("doctest")

target("evaluate-boolean-binary-tree")
    set_kind("binary")
    add_packages("doctest")
    add_files("src/evaluate-boolean-binary-tree.cpp")
