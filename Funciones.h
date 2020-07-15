#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


void puntajeTotal(int);

int cantidadParticipantes();

void ingresarParticipantes(Jugador * , int );

void mostrarParticipantes(Jugador * , int);

void banner();

void guardarParticipantesEnDisco(Jugador *, int );

void leerParticipantesDeDisco(Jugador *, int );

void turnoDeParticipantes(Jugador *, int );

bool verificar(int *,int , int );

void mostrarNombre(char *, int);


#endif // FUNCIONES_H_INCLUDED
