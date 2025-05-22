/* ******
* F11LeerCadenaConFormato
* Que permita leer un número determinado de caracteres con un formato pasado como parámetro y retorne la 
  cadena leída sólo hasta que sea correcta, por ejemplo, un RFC, la función podría recibir como argumento la 
  cadena “AAAA999999XXX” que indica que debe leer primero sólo cuatro caracteres alfabéticos, luego seis 
  dígitos y por último tres caracteres cualesquiera.
  * Autor: Zuri
 ****** */ 
char *LeerCadenaConFormato(char *sFormato) {
    static char sCadena[100];
    int eLongitud = strlen(sFormato);
    int eContador;
    int lCadenaValida;
    
    while (1) {
        ValidarCadena(sCadena, eLongitud);

        lCadenaValida = 1;

        for (eContador = 0; eContador < eLongitud; eContador++) {
            char c = sCadena[eContador];
            char tipo = sFormato[eContador];

            if (tipo == 'A' && !isalpha(c)) {
                lCadenaValida = 0;
            } else if (tipo == '9' && !isdigit(c)) {
                lCadenaValida = 0;
            } else if (tipo == 'X' && !isalnum(c)) {
                lCadenaValida = 0;
            }
        }

        if (lCadenaValida) {
            return sCadena;
        } else {
            MensajeError(11);
        }
    }
}