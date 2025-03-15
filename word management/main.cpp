#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word{
  char val[20];
  struct word * left;
  struct word * right;
};

struct word_list{
    char val[20];
    struct word_list * next;
};

int get_hashmap_index(char cuvant[20]){

    return cuvant[0] - 'a';
}

struct word * create_new_word(char cuvant[20]){
    struct word * new_node = malloc(sizeof(struct word));
    new_node->left = NULL;
    new_node->right = NULL;
    strcpy(new_node->val, cuvant); //

    return new_node;
}


void add_node(struct word * root, char cuvant[20]){

    struct word * new_node = create_new_word(cuvant);
    struct word * current = root;
    while(current != NULL){

        if(strcmp(cuvant, current->val) < 0){//punem la stanga
            if(current->left == NULL){
                current->left = new_node;
                break;
            }
            else{
                current = current->left;
            }

        }
        else{
            if(strcmp(cuvant, current->val) > 0){//punem la dreapta
                if(current->right == NULL){
                    current->right = new_node;
                    break;
                }
                else{
                    current = current->right;
                }
        }

    }

    }
}

void print_preordine(struct word * node){
    //printf("am ajuns aici");
    //printf("%p", node);
    if(node != NULL){
        printf("%s\n", node->val);
        print_preordine(node->left);
        print_preordine(node->right);
    }
}

void print_inordine(struct word * node){

    if(node != NULL){

        print_inordine(node->left);
        printf("%s\n", node->val);
        print_inordine(node->right);
    }
}

struct word_list * add_node_list(struct word_list * head, char cuvant[20]){

    // create new node
    struct word_list * new_node = malloc(sizeof(struct word_list));
    strcpy(new_node->val,  cuvant);
    new_node -> next = NULL;

    if(head == NULL){
        return new_node;
    }
    else{
        struct word_list * current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
    return head;

}

int get_list_index(struct word_list * head, char cuvant[20]){

    struct word_list * current = head;
    int index = 0;
    while(current != NULL){
        if(strcmp(current->val, cuvant) == 0){
            index ++;
            break;
        }
        //printf("%d\n", index);
        index++;
        current = current->next;
    }
    return index;

}

int get_tree_index(struct word * root, char cuvant[20]){

    struct word * current = root;
    int index=0;
    int cmp;
    while(current != NULL){

        cmp = strcmp(cuvant, current->val);
        index ++;
        if(cmp == 0){
            break;
        }
        if(cmp < 0){
            // mergem la stanga
            current = current->left;
        }
        if(cmp > 0){
            // mergem la dreapta
            current = current->right;
        }

    }
    return index;
}


int main(){

    struct word * hashmap[26] = {NULL};
    struct word_list * list = NULL;
    char temp[20], cuvant[20];
    int functie;
    char litera;

    for(int i=0;i<1000;i++){

        scanf("%s", temp);
        if(strcmp(temp, "stop") == 0){
            break;
        }
        list = add_node_list(list, temp);

        if(hashmap[get_hashmap_index(temp)] == NULL){
            hashmap[get_hashmap_index(temp)] = create_new_word(temp);
        }
        else{
            add_node(hashmap[get_hashmap_index(temp)], temp);
        }

    }

    scanf("%d", &functie);
    if(functie == 1){

        //printf("%d", functie);
        getchar();
        scanf("%c", &litera);
        //printf("%c", litera);
        print_preordine(hashmap[litera - 'a']);
    }
    if(functie == 2){
        for(int i=0;i<26; i++){
            //printf("\n");
            print_inordine(hashmap[i]);
        }
    }
    if(functie == 3){
        scanf("%s", cuvant);
        //printf("%s", cuvant);
        printf("%d\n", get_tree_index(hashmap[get_hashmap_index(cuvant)], cuvant));
        printf("%d", get_list_index(list, cuvant));
    }


    return 0;
}
