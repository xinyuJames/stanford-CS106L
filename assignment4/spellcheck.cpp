#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  // find all iteratr for space
  std::vector<std::string::iterator> space_it;
  space_it = find_all(source.begin(), source.end(), std::isspace);

  // token set, inserter to insert into
  Corpus tokens;
  std::transform(space_it.begin(), space_it.end()-1, space_it.begin()-1,
    std::inserter(tokens, tokens.end()), [source](auto begin, auto end){ return (new Token(source, begin, end)); });

  std::erase_if(tokens, [](Token t){ return t.content.empty(); });
  
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  return std::set<Misspelling>();
};

/* Helper methods */

#include "utils.cpp"