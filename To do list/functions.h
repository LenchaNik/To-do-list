#pragma once
#include <string>

//show_menu-Выводит меню в консоль
void show_menu();

//add_note-добавить заметку
void add_note(const std::string& new_note);

//see_all_notes - показать все заметки
void see_all_notes();

//find_one_one - поиск одной заметки
std::string* find_one_note(const std::string& note_to_find,int& n_count) ;


//возвращает указатель на массив всех заметок
std::string* all_notes(int& n_count);

//удаляет одну заметку под индексом choice -1
void remove_one_note(std::string* all_notes_arr,int count, int choice);

//удаляет все заметки
void remove_all_notes();



