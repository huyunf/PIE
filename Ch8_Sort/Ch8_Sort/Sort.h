#pragma once

#include <vector>

template <class Type>
class sort {
public:
	
	sort(std::vector<Type> ary):origin_ary(ary){}

	void swap(Type &a, Type &b);

	void selected_sort(void);

	void insert_sort(void);

private:
	std::vector<Type> origin_ary;

	std::vector<Type> selected_sort_ary;

	std::vector<Type> insert_sort_ary;
};

template <typename Type>
void sort<Type>::swap(Type &a, Type &b)
{

	Type tmp = a;
	a = b;
	b = tmp;
}


template <typename Type>
void sort<Type>::selected_sort(void)
{
	selected_sort_ary = origin_ary;

	for (vector<Type>::iterator iter = selected_sort_ary.begin(); iter != selected_sort_ary.end(); iter++) {

		Type Min = *iter;

		for (vector<Type>::iterator sub_iter = iter + 1; sub_iter != selected_sort_ary.end(); sub_iter++) {

			if (*sub_iter < Min) {
				Min = *sub_iter;
				
				swap(*iter, *sub_iter); 
			}
		}
	}
}

template <typename Type>
void sort<Type>::insert_sort(void)
{
	insert_sort_ary.clear();

	for (vector<Type>::iterator orig_iter = origin_ary.begin(); orig_iter != origin_ary.end(); orig_iter++) {
		
		if (insert_sort_ary.size() == 0) 
			insert_sort_ary.push_back(*orig_iter);
		else {
			for (vector<Type>::iterator dst_iter = insert_sort_ary.begin(); dst_iter != insert_sort_ary.end(); dst_iter++) {
				if (*dst_iter > *orig_iter){
					insert_sort_ary.insert(dst_iter, *orig_iter);
					break;
				}
				if (dst_iter == insert_sort_ary.end() - 1) {
					insert_sort_ary.insert(insert_sort_ary.end(), *orig_iter);
					break;
				}
			}
		}
	}

}

