#include <iostream> 
#include <stdio.h>
#include <queue>

using namespace std;  

class Pet {
protected: 
    string type;

public:
    Pet(string category) {
        this->type = category;
    }
    string getPetType() {
        return this->type;
    }
};

class dog: public Pet {
public:
    dog(): Pet("dog") {}
};

class cat: public Pet {
public:
    cat(): Pet("cat") {}
};

class PetEnterQueue {
private:
    Pet  pet;
    long count;  //记录第几个
public:
    PetEnterQueue(Pet name, long num) {
        this->pet = name;
        this->count = num;
    }

    Pet get_Pet() {
        return this->pet;
    }
    long get_Count() {
        return this->count;
    }

    string getEnterPetType() {
        return this->pet.getPetType();
    }
};

class DogCatQueue {
private:
    queue<PetEnterQueue> dogs;
    queue<PetEnterQueue> cats;
    long counts;
public:
    DogCatQueue() {
        counts = 0;
    }

    void add(Pet pet) {
        if(pet.getPetType() != "dog" && pet.getPetType() != "cat") {
            printf("Error: this pet is neither dog nor cat");
            return;
        } else if(pet.getPetType() == "dog") {
            PetEnterQueue animal(pet, ++counts);
            dogs.push(animal);
        } else {
            PetEnterQueue animal(pet, ++counts);
            cats.push(animal);
        }
    }

    Pet popAll() {
        if(dogs.size() > 0 && cats.size() >0) {
           if(dogs.front().get_Count() < cats.front().get_Count()) {
               Pet tmp = dogs.front().get_Pet();
               dogs.pop();
               return tmp;
           } else {
               Pet tmp = cats.front().get_Pet();
               cats.pop();
               return tmp;
           }
        } else if(dogs.size() > 0) {
            Pet tmp = dogs.front().get_Pet();
            dogs.pop();
            return tmp;  
        } else if (cats.size() > 0) {
            Pet tmp = cats.front().get_Pet();
            cats.pop();
            return tmp;
        } else {
            printf("Error: queue is empty!\n");
            Pet monster("Monster");
            return monster;
        }
    }   

    dog popDog() {
        if(dogs.size() <= 0) {
            printf("Error: dog queue is empty!\n");
        } else {
            dog tmp = (dog) dogs.front().get_Pet();
            dogs.pop();
            return tmp;
        }
    }

    cat popCat() {
        if(cats.size() <= 0) {
            printf("Error: cat queue is empty!\n");
        } else {
            cat tmp = (cat) cats.front().get_Pet();
            cats.pop();
            return tmp;
        }
    }

    bool isEmpty() {
        return dogs.empty() && cats.empty();
    }

    bool isDogQueueEmpty() {
        return dogs.empty();
    }

    bool isCatQueueEmpty() {
        return cats.empty();
    }
};

int main(int argc, char** argv) {
    char text[20];
    DogCatQueue test;

    dog dog1;
    dog dog2;
    dog dog3;
    cat cat1;
    cat cat2;
    cat cat3;

    test.add(dog1);
    test.add(cat1);
    test.add(dog2);
    test.add(cat2);
    test.add(dog3);
    test.add(cat3);

    while(!test.isDogQueueEmpty()) {
        sprintf(text, test.popDog().getPetType());
        printf(text);
    }

    while(!test.isEmpty()) {
        printf(test.popAll().getPetType());
    }

    return 0;
}


