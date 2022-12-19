#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/* Exercicio 1: 
    circular as bolas detectadas pelo algoritmo
*/
int main(int argc, char **argv)
{
    // inicializa o detector de bola usando o treinamento ballgithub.xml
    CascadeClassifier cascade;
    cascade.load("../ballgithub.xml");

    // le a imagem recebida por parametro
    Mat img_original = imread(argv[1]);
    // faz uma copia da imagem para edita-la
    Mat img_editada = img_original.clone();
    // verifica se a imagem esta vazia, ou seja, nao conseguiu abri-la
    if (img_original.empty()){
	cout << "eh necessario passar uma imagem como argumento para o programa" << endl << 
	    "./hello image.png" << endl;
	    return -1;
    }

    Mat img_cinza;
    cvtColor(img_original, img_cinza, COLOR_BGR2GRAY); // converte a img_original de BGR para Escala de Cinza e escreve na img_cinza
    std::vector<Rect> balls;
    // cascade.detectMultiScale(frame_gray, balls, 1.1, 5, 8, Size(16, 16));
    cascade.detectMultiScale(img_cinza, balls, 1.3, 5, 8, Size(16, 16)); // Roda o detector de bola na imagem cinza. Os resultados sao gravados no vetor balls
    /* o vetor balls eh um vetor contendo os retangulos (bounding boxes) onde foram detectados bola.
       cada Rect tem as seguintes propriedades:
       width, height, x, y;
       exemplo: cout << balls[i].height << endl;
     */
    // mostra as imagens
    imshow("imagem original", img_original);
    imshow("imagem cinza", img_cinza);
    waitKey(); // espera o usuario apertar alguma tecla do teclado
    return 0;
}
