# Socket internet
Un simple sistema socket AF_INTERNET y STREAM, ejecutado localmente, con un servidor y un unico cliente, para intercambios de mensajes.

## Threads
El manejo de hilos para enviar y recibir mensajes garantiza que la comunicación sea fluida, pudiendo enviar multiples mensajes a la vez antes de recibir una respuesta.

## Test
Luego de su compilación, para su prueba simplemente ejecutar en la terminal del cliente:
```bash
./bin/client
```

Luego en la terminal del servidor:
```bash
./bin/server
```

Ahora podrá enviar mensajes de una terminal a la otra escribiendo en cualquiera de ellas.
