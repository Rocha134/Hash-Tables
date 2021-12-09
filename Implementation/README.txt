programa en C++ que implemente una tabla de dispersión que maneje las colisiones con el métodos de Dirección Abierta de la prueba lineal (reacomodando el elemento colisionado dentro de la tabla).
Implementa la función hash y todas las operaciones para que trabaje bien la tabla hash.

Escribe también un programa principal que trabaje con autos de acuerdo al siguiente MENU ciclado

1. insertar  (si la tabla ya esta llena, mandar mensaje "tabla llena, imposible insertar", si ya existe la placa, mandar mensaje "imposible insertar, placa duplicada")
2. eliminar
3. imprime la tabla
(se muestra el índice, se muestran todos los datos de la tabla, un dato por línea)
4. buscar un dato  (si el dato no esta se imprime "dato no encontrado")
0. salir

La tabla HASH debe ser de tamaño 97, y los datos con los que se va a trabajar,
se componen de 4 campos:
  placa (string de 7 chars)
  marca (string)
  modelo (string)
  anio (int)
donde la llave es el campo de placa

La función HASH debe sumar el código ASCII de cada char y le aplica módulo 97 para encontrar la posición en la tabla.

Escribe un caso de prueba en el que compruebes que hay colisiones.
(Al menos 3 elementos colisionan en el mísmo índice)

Cada vez que se ejecuta una operación, al final se debe imprimir una linea en blanco (que servira como seaprador visual de cada parte del output)

ejemplo de entrada :
1
TXW8765
volkswagen
jetta
2005
1
TRS7162
honda
fit
2018
1
TYU7848
kia
forte
2016
3
4
TXW8765
2
TXW8765
3
0

output
0
1
2
.
.
.
67
68
69 TRS7162 honda fit 2018
70
71
.
.
.
87
88
89 TXW8765 volkswagen jetta 2005
90 TYU7848 kia forte 2016
91
92
89
.
.
.
96

TXW8765 volkswagen jetta 2005

0
1
2
.
.
.
67
68
69 TRS7162 honda fit 2018
70
71
.
.
.
87
88
89
90 TYU7848 kia forte 2016
91
92
89
.
.
.
96
