import java.util.Hashtable;
import java.util.Iterator;

public class XifresResolver {

	private int solucioABuscar;

	private Node millorSolucioTrobada;
	
	private Node nodeActual;

	private Hashtable<Integer, Node> nodesJaExplorats;

	public int getSolucioABuscar() {
		return solucioABuscar;
	}

	public void setSolucioABuscar(int solucioABuscar) {
		this.solucioABuscar = solucioABuscar;
	}

	public Node getMillorSolucioTrobada() {
		return millorSolucioTrobada;
	}

	public void setMillorSolucioTrobada(Node millorSolucioTrobada) {
		this.millorSolucioTrobada = millorSolucioTrobada;
	}

	public XifresResolver() {
		// TODO Auto-generated constructor stub
		this.setMillorSolucioTrobada(new Node());
	}

	/*
	 * @return retorna el següent node candidat o null si no hi han més
	 * candidats
	 */
	public Node obtenirSeguentNodeCandidat() {

		//Recorre
		for(Iterator it = this.getNodeActual().getOperands().iterator();it.hasNext();) {
		//	it.
		}
		return new Node();

	}
	
	public void actualitzarMillorSolucioTrobada() {
		
		int resultatActual = this.getNodeActual().getOperands().peek().intValue();
		int solucio = this.getSolucioABuscar();
		Operand	opMillorResultat =	this.getMillorSolucioTrobada().getOperands().peek();
		int millorResultat= 0;
		if (opMillorResultat!=null)
			millorResultat= opMillorResultat.intValue();
		if ( (Math.abs(solucio -resultatActual)) < (Math.abs(solucio -millorResultat))) {
			this.setMillorSolucioTrobada(this.getNodeActual());
		}
		
	}
	
	

	boolean resoldreXifres() {
		/*
		 * MENTRE QuedenCandidats AND NO Encertat FER 
		 *  Seleccionar I Esborrar
		 *  Candidat SI Acceptable LLAVORS Anotar Candidat SI NO Solucio Completa
		 * LLAVORS Backtracking Pas Seguent {Crida Recursiva} SI NO Encertat
		 * LLAVORS Desanotar Candidat FSI ALTRAMENT Encertat:= Cert FSI FSI
		 * FMENTRE
		 */

		// Menstrestant quedin candidats i no s'ha trobat la solució

		// Selecciona un candidat
		
		this.actualitzarMillorSolucioTrobada();
		
		Node nodeactual = this.getNodeActual();
		
		if (nodeactual.obtenirResultatParcialNode()==this.getSolucioABuscar()) {
			return true;
		}
		// Candidat acceptable? En principi tots ho són però per no fer un algorisme de 
		// força bruta almenys comprovarem que el node no s'hagi utilitzat ja
		
		//és una fulla
		if (nodeactual.getOperands().size()==1) {
			return false;
		}
		
		for (Iterator<Node> it = this.getNodeActual().getFills().iterator(); it.hasNext();) {
			Node fill = it.next();
			fill.calcularFills();
			
			this.setNodeActual(fill);
			if (this.resoldreXifres()) {
				return true;
			}
		}
		return false;
	}

	public static void main(String[] args) {
		
		XifresResolver resolver = new XifresResolver();
		
		// args Cada argument conté una xifra i l'argument final és la solució a
		// buscar
		if (args.length != 7) {
			System.out.println("Nombre d'arguments incorrecte");
		}

		// Iniciar el conjunt de candidats
		// El càlcul de candidats no és obvi en aquest cas i s'aniran calculen a
		// mesura que es necessitin
		
		//Node inicial. 6 operands
		Node nodeinicial = new Node();
		
		for (int i=0;i<6;i++) {
			nodeinicial.getOperands().add( new Operand( (new Integer(args[i])) ) );
		}
		resolver.setSolucioABuscar(new Integer(args[6]).intValue());
		
		nodeinicial.calcularFills();
		
		//Iniciar la resolució del problema
		
		resolver.setNodeActual(nodeinicial);
		
		if (resolver.resoldreXifres()) {
			//Mostrar resultat
			System.out.println("S'ha trobat una solució");
			resolver.millorSolucioTrobada.mostrarResultat();
		}
		else {
			//Mostrar millor resultat trobat
			System.out.println("No s'ha trobat una solució exacte");
			resolver.millorSolucioTrobada.mostrarResultat();
		}
		
	}

	public Node getNodeActual() {
		return nodeActual;
	}

	public void setNodeActual(Node nodeactual) {
		this.nodeActual = nodeactual;
	}

	public Hashtable<Integer, Node> getNodesJaExplorats() {
		return nodesJaExplorats;
	}

	public void setNodesJaExplorats(Hashtable<Integer, Node> nodesJaExplorats) {
		this.nodesJaExplorats = nodesJaExplorats;
	}
}
