#include "Fachada_Servidor.h"

Fachada_Servidor::Fachada_Servidor(
    Nat cantJugadores,
    const Fachada_Variante& variante,
    const Repositorio& r
) {
    Fachada_Variante v = variante;
    Servidor s(cantJugadores, r, v.variante_interna());
    servidor = s;
}

IdCliente Fachada_Servidor::conectarCliente() { return servidor.conectar_cliente(); }

void Fachada_Servidor::recibirMensaje(IdCliente id, const Ocurrencia& o) { servidor.recibir_mensaje(id, o); }

Nat Fachada_Servidor::jugadoresEsperados() { return servidor.esperados(); }

Nat Fachada_Servidor::jugadoresConectados() { return servidor.conectados(); }

std::list<Notificacion> Fachada_Servidor::notificaciones(IdCliente id) { return servidor.consultar(id); }
