
public class Reina {

	
	private int fila;
	
	private int columna;

	public int getFila() {
		return fila;
	}

	public void setFila(int fila) {
		this.fila = fila;
	}

	public int getColumna() {
		return columna;
	}

	public void setColumna(int columna) {
		this.columna = columna;
	}
	
	public Reina() {
		// TODO Auto-generated constructor stub
	}
	
	public Reina(int fila, int columna) {
		this.setFila(fila);
		this.setColumna(columna);
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return "(" + this.getFila() + "," + this.getColumna() + ")";
	}
}
