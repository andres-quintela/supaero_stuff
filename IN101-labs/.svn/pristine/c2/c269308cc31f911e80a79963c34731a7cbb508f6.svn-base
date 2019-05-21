#include "bst-map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




bst_tree *nil_tree(void){
	
	
	bst_tree *p_tree = malloc(sizeof(bst_tree));
	
	*p_tree=NULL;
	
	
	return p_tree; 
}


bool insert(bst_tree *p_tree,game_map *map_struct){
	
	
	//case in which tree is empty
	if (*p_tree==NULL){
		
		//allocate new node cell
		bst_node *node=malloc(sizeof(bst_node));
		
		(*node).map_struct=map_struct;
		(*node).big=NULL;
		(*node).small=NULL;
		
		*p_tree=node;
		//map is not explored so return false
		return false;
		}
	
	bst_node *loop =*p_tree;
	
	bool end =0;
	
	//exploring the tree
	while (end!=1){
		int result = strncmp((*(*loop).map_struct).map_array,(*map_struct).map_array,((*map_struct).height*(*map_struct).width));
		
		if ((result<0)&&((*loop).small!=NULL)){
			
			loop=(*loop).small;
			
		}
		
		else if ((result<0)&&((*loop).small==NULL)){
			
			//create new cell
	
			bst_node *node=malloc(sizeof(bst_node));
			(*node).map_struct=map_struct;
			(*node).big=NULL;
			(*node).small=NULL;
			
			(*loop).small=node;
			return false;
		}
		
		else if ((result>0)&&((*loop).big!=NULL)){
			
			loop=(*loop).big;
			
		}
		
		else if ((result>0)&&((*loop).big==NULL)){
			
			//create new cell

			
			bst_node *node=malloc(sizeof(bst_node));
			(*node).map_struct=map_struct;
			(*node).big=NULL;
			(*node).small=NULL;
			
			(*loop).big=node;
			return false;
		}
		
		else if (result==0)
		end =1;
			//map has already been explored
	}
return true;
}



void deallocate_tree(bst_tree *p_tree){
	
	bst_node* current;
	bst_node* next;
	current = *p_tree;
	
	
	while(((*(*p_tree)).big != NULL)||((*(*p_tree)).small != NULL)){
	//explore leftmost sides	
	if (((*current).big != NULL) && (((*(*current).big).big != NULL) || ((*(*current).big).small != NULL))){
		current=(*current).big;
		}
	else if (((*current).big != NULL) && (((*(*current).big).big == NULL) || ((*(*current).big).small == NULL))) {
		next=(*current).big;
		free((*(*next).map_struct).map_array);
		free((*next).map_struct);
		free(next);
		(*current).big=NULL;
		current=*p_tree;
		}	
	else if (((*current).small != NULL) && (((*(*current).small).big != NULL) || ((*(*current).small).small != NULL))){
		
		current=(*current).small;
		}
	else {

		next=(*current).small;
		free((*(*next).map_struct).map_array);
		free((*next).map_struct);
		free(next);
		(*current).small=NULL;
		current=*p_tree;
		}		
	}
free((*(*current).map_struct).map_array);
free((*current).map_struct);
free(current);
free(p_tree);
}
