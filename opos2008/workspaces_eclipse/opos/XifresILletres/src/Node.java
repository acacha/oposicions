import java.util.ArrayList;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Vector;

public class Node {

	private PriorityQueue<Operand> operands;

	private ArrayList<Node> fills;

	// Conté les operacions que s'han fet per arribar a aquest node des de el
	// node arrel
	private Vector<String> operacions;
	
	public PriorityQueue<Operand> getOperands() {
		return operands;
	}

	public void setOperands(PriorityQueue<Operand> operands) {
		this.operands = operands;
	}

	public Node() {
		// TODO Auto-generated constructor stub
		this.setOperands(new PriorityQueue<Operand>());
		this.setOperacions(new Vector<String>());
		this.setFills(new ArrayList<Node>());
	}

	// El primer element sempre conté el resultat parcial del node
	public int obtenirResultatParcialNode() {
		return this.getOperands().peek().intValue();
	}

	public void mostrarResultat() {
		for (Iterator<Operand> it = this.getOperands().iterator(); it.hasNext();) {
			Operand op = it.next();
			System.out.println("(" + op.getOperacions() + ") = " +this.obtenirResultatParcialNode());
		}
	}

	private Node nouFill(Operand primerElement,
			PriorityQueue<Operand> restaElements, String operacio,
			Vector<String> operacionsPare) {
		Node fill = new Node();
		fill.getOperands().add(primerElement);
		fill.getOperands().addAll(restaElements);
		fill.getOperacions().addAll(operacionsPare);
		fill.getOperacions().add(operacio);
		return fill;
	}

	public void calcularFills() {
		int nOperands = this.getOperands().size();

		PriorityQueue<Operand> copia = new PriorityQueue<Operand>();
		PriorityQueue<Operand> copia2 = new PriorityQueue<Operand>();

		// Obtenir una copia
		for (Iterator<Operand> it = this.getOperands().iterator(); it.hasNext();) {
			this.getOperands().poll()
			copia.add(it.next());
		}

		for (Iterator<Operand> it = this.getOperands().iterator(); it.hasNext();) {
			Operand operand = it.next();
			copia.poll();
			for (Iterator<Operand> it3 = copia.iterator(); it3.hasNext();) {
				copia2.add(it3.next());
			}
			for (Iterator<Operand> it1 = copia.iterator(); it1.hasNext();) {
				Operand nextOperand = it1.next();
				// Suma
				int suma = nextOperand.intValue() + operand.intValue();
				String operacio= nextOperand + " + " + operand; 
				copia2.peek();
				this.getFills().add(
						this.nouFill(new Operand(suma,operacio), copia2, "+", this
								.getOperacions()));

				// Resta
				int resta = nextOperand.intValue() - operand.intValue();
				operacio= nextOperand + " - " + operand;
				this.getFills().add(
						this.nouFill(new Operand(resta,operacio), copia, "-", this
								.getOperacions()));

				// Multiplicacio
				int multiplicacio = nextOperand.intValue()
						* operand.intValue();
				operacio= nextOperand + " * " + operand;
				this.getFills().add(
						this.nouFill(new Operand(multiplicacio,operacio), copia, "*",
								this.getOperacions()));

				// Divisio
				if ((nextOperand.intValue() % operand.intValue())==0)	{
					int divisio = nextOperand.intValue() / operand.intValue();
					operacio= nextOperand + " / " + operand;
					this.getFills().add(
							this.nouFill(new Operand(divisio,operacio), copia, "/",
									this.getOperacions()));	
				}
			}
		}

	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return this.getOperands().toString();
	}

	public ArrayList<Node> getFills() {
		return fills;
	}

	public void setFills(ArrayList<Node> fills) {
		this.fills = fills;
	}

	public Vector<String> getOperacions() {
		return operacions;
	}

	public void setOperacions(Vector<String> operacions) {
		this.operacions = operacions;
	}

}
