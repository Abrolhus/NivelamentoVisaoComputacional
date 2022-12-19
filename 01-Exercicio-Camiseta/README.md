# Exercício 2: Detecção de Camisetas:
Dada uma imagem, pintar as camisetas dos robôs com uma cor qualquer.

### Dicas:
Uma imagem pode ser percorrida, acessando-a pixel a pixel.
```c++
for (int i = 0; i < img_editada.cols; i++){
  for (size_t j = 0; j < img_editada.rows; j++){
    img_editada.at<Vec3b>(j, i) = Vec3b{255, 0, 255};
  }
}
```
