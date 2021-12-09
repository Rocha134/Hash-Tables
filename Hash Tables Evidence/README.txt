
    Lea el archivo de entrada "bitacora.txt".
    Crear una tabla hash cuya llave sea el dominio y cuyo valor sea un resumen de ese dominio. Este resumen deberá incluir, el número de accesos, el número de conexiones (ip únicos) así como las ips de ese dominio ordenadas de manera ascendente NO Ajustados a 3 dígitos. El tamaño de la tabla debe ser el numero primo más grande que sea menor a 32768.
    Si llegara a pasar que la tabla se llena y ya no puede recibir más datos, mandar un mensaje de Error "Tabla llena, imposible meter más datos"
    Realiza un método que dado un nombre de un dominio regrese el valor asociado a él desplegando la información de una manera adecuada

Tu programa recibe como entrada un número N , seguido de N dominios

La salida es para cada dominio, el resumen del dominio

Ejemplo de entrada:
2
145.25
85.25

Ejemplo de salida:
145.25
34
4
145.25.32.15
145.25.45.21
145.25.98.125
145.25.178.65

85.25
12
3
85.25.65.125
85.25.99.74
85.25.145.25
