#ifndef BLOOMPART_H
#define BLOOMPART_H



class BloomPart{
private:
    map<string, ICommand*> commands;
    int* arr;

public:
    BloomPart(map<string, ICommand*> commands, int arr[]); // Constructor declaration
    void run();
};

#endif // BLOOMPART_H