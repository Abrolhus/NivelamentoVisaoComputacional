#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    
    // le a imagem recebida por parametro
    Mat img_original = imread(argv[1]);
    // faz uma copia da imagem para edita-la
    Mat img_editada = img_original.clone();
    // redimensiona a imagem para 800x600
    cv::resize(img_editada, img_editada, Size(800, 600));
    // verifica se a imagem esta vazia, ou seja, nao conseguiu abri-la
    if (img_original.empty()){
	cout << "eh necessario passar uma imagem como argumento para o programa" << endl << 
	    "./hello image.png" << endl;
	    return -1;
    }
    // Mat frameGrande(Size(640, 480), CV_8UC3);
    /// como percorrer a imagem e acessar pixel a pixel
    /*
    for (int i = 0; i < img_editada.cols; i++)
    {
	for (size_t j = 0; j < img_editada.rows; j++)
	{
	    img_editada.at<Vec3b>(j, i) = Vec3b{255, 0, 255};
	}
    }
    */
    /// funções de desenho! (mais em //https://docs.opencv.org/2.4.13.7/modules/core/doc/drawing_functions.html?highlight=puttext)
    /// como desenhar um circulo?
    circle(img_editada, Point(200, 400), 60, Scalar(0, 0, 255), CV_FILLED);
    /// como desenhar um retangulo?
    rectangle(img_editada, Point(300, 300), Point(400, 500), Scalar(255, 0, 0), 5);
    // como escrever um texto (o 2 eh o tamanho (escala) da fonte, o 3 a grossura da linha)
    putText(img_editada, "Hello OpenCV!", Point(100 ,100), FONT_HERSHEY_SIMPLEX, 2, Scalar(0,50,240), 3);

    /// mostra duas janelas, uma com a imagem original, outra com a imagem editada. A janela com a imagem original vai ficar embaixo da com a imagem modificada!
    imshow("imagem original", img_original);
    imshow("imagem rabiscada", img_editada);
    // espera o usuario apertar alguma tecla do teclado
    waitKey();
    return 0;
}
