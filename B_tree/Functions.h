#pragma once

#include "Tree.h"

void Insert(Tree& tree);
void Print(const Tree& tree);
void PrintMenu();
void Remove(Tree& tree);
void Search(const Tree& tree);
void Edit(const Tree& tree);
void toFile(const Tree& tree, const char* path);