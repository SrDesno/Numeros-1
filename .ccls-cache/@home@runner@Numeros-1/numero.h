class numero
{
    //abstracción
    private:
        int num;

    public:
        numero();//constructor
        void setNumero(); //Método modificador
        int getNumero(); //Método accesor
        int sumaNumeros(int n);
        int sumaNumeros(numero n2);
        virtual ~numero();
};