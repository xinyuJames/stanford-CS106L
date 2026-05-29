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

  // find all iterator for space
  auto space_it = find_all(source.begin(), source.end(), [](char c){ return std::isspace(c); });

  // token set, insert Token to end of tokens iterator
  Corpus tokens;
  std::transform(space_it.begin(), space_it.end()-1, space_it.begin()+1,
    std::inserter(tokens, tokens.end()), [&source](auto beg, auto en){ return (Token(source, beg, en)); });

  // erase token with empty content
  std::erase_if(tokens, [](Token t){ return t.content.empty(); });
  
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  auto view = source 
    // filter out correct words
    | std::ranges::views::filter([&dictionary](const Token& cur){ return !dictionary.contains(cur.content); })
    // transform into Misspelling type, with suggestions 1 char away
    | std::ranges::views::transform([&dictionary](const Token& cur){
      // make one_away set
      auto one_away = dictionary | std::ranges::views::filter([&cur](const std::string& dic){
        return levenshtein(cur.content, dic) == 1;
      });
      std::set<std::string> suggestions(one_away.begin(), one_away.end());

      return Misspelling(cur, suggestions);
    })
    // filter out misspelling with no suggestion
    | std::ranges::views::filter([](const Misspelling& cur){ return !cur.suggestions.empty(); });

  // return as a set
  return std::set<Misspelling>(view.begin(), view.end());
};

/* Helper methods */

#include "utils.cpp"