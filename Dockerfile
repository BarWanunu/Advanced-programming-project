FROM gcc:latest

WORKDIR /user/src/myprogram

COPY ./src/ .

RUN g++ -o myprogram ./main.cpp ./InputArr.cpp ./BloomPart.cpp ./AddURL.cpp ./CheckURL.cpp ./BytesArray.cpp ./URLlist.cpp ./HashFunction.cpp ./Node.cpp

EXPOSE 5555

CMD ["./myprogram"]
