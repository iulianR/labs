  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  int tableSize = 0, totalElem = 0;
  struct node *hashTable = NULL;

  struct node {
        int age, key;
        char name[100];
        int marker;
  };

  void insertInHash(int key, char *name, int age) {
        int hashIndex = key % tableSize;
        if (tableSize == totalElem) {
                printf("Nu se poate insera. Tabela de dispersie e plina !");
                return;
        }
        while (hashTable[hashIndex].marker == 1) {
                hashIndex = (hashIndex + 1) % tableSize;
        }
        hashTable[hashIndex].key = key;
        hashTable[hashIndex].age = age;
        strcpy(hashTable[hashIndex].name, name);
        hashTable[hashIndex].marker = 1;
        totalElem++;
        return;
  }

  void deleteFromHash(int key) {
        int hashIndex = key % tableSize, count = 0, flag = 0;
        if (totalElem == 0) {
                printf("Tabela de dispersie este vida !\n");
                return;
        }

        while (hashTable[hashIndex].marker != 0 && count <= tableSize) {
                if (hashTable[hashIndex].key == key) {
                        hashTable[hashIndex].key = 0;
                        /* set marker to -1 during deletion operation*/
                        hashTable[hashIndex].marker = -1;
                        hashTable[hashIndex].age = 0;
                        strcpy(hashTable[hashIndex].name, "\0");
                        totalElem--;
                        flag = 1;
                        break;
                }
                hashIndex = (hashIndex + 1)%tableSize;
                count++;
        }

        if (flag)
                printf("Datele au fost sterse din tabela de dispersie\n");
        else
                printf("Datele nu exista in tabela de dispersie\n");
        return;
  }

  void searchElement(int key) {
        int hashIndex = key % tableSize, flag = 0, count = 0;
        if (totalElem == 0) {
                printf("Tabela de dispersie este vida !");
                return;
        }
        while (hashTable[hashIndex].marker != 0 && count <= tableSize) {
                if (hashTable[hashIndex].key == key) {
                        printf("Cheie: %d\n", hashTable[hashIndex].key);
                        printf("Nume: %s\n", hashTable[hashIndex].name);
                        printf("Varsta: %d\n", hashTable[hashIndex].age);
                        flag = 1;
                        break;
                }
                hashIndex = (hashIndex + 1)%tableSize;
        }

        if (!flag)
                printf("Datele nu exista in tabela de dispersie\n");
        return;
  }

  void display() {
        int i;
        if (totalElem == 0) {
                printf("Tabela de dispersie este vida !\n");
                return;
        }
        printf("Cheie        Nume           Varsta    Index\n");
        printf("-------------------------------------------\n");
        for (i = 0; i < tableSize; i++) {
                if (hashTable[i].marker == 1) {
                        printf("%-13d", hashTable[i].key);
                        printf("%-15s", hashTable[i].name);
                        printf("%-7d", hashTable[i].age);
                        printf("%d\n", i);
                }
        }
        printf("\n");
        return;
  }

  int main() {
        int key, age, ch;
        char name[100];
        printf("Introduceti numarul de elemente: ");
        scanf("%d", &tableSize);
        hashTable = (struct node *)calloc(tableSize, sizeof(struct node));
        while (1) {
                printf("1. Inserare\t2. Stergere\n");
                printf("3. Cautare\t4. Afisare\n");
                printf("5. Terminare\nIntroduceti valoarea: ");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Introduceti cheia: ");
                                scanf("%d", &key);
                                getchar();
                                printf("Numele: ");
                                fgets(name, 100, stdin);
                                name[strlen(name) - 1] = '\0';
                                printf("Varsta: ");
                                scanf("%d", &age);
                                insertInHash(key, name, age);
                                break;
                        case 2:
                                printf("Introduceti cheia pe care o stergeti: ");
                                scanf("%d", &key);
                                deleteFromHash(key);
                                break;
                        case 3:
                                printf("Introduceti cheia pe care o cautati: ");
                                scanf("%d", &key);
                                searchElement(key);
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(0);

                        default:
                                printf("Ati introdus o optiune gresita !\n");
                                break;
                }
        }
        return 0;
  }
