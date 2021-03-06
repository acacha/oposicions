import java.awt.*;
import java.awt.event.*;

/*
  
  8-Queens Applet, By Aaron Davidson <http://spaz.ca/>
  
  This code is released in the public domain. The author
  would appreciate it if any derivatives or distributions
  retain this comment & credit.
  
 */

public class Board {
	int[][] grid = new int[8][8];
	int gWidth,gHeight;
		
	public Board() {
		initBoard();
	}
	
	public void initBoard() {
		for (int i=0;i<8;i++) 
			for (int j=0;j<8;j++)
				grid[i][j] = 0;
	}
	
	
	/**
	 * Adds (or removes) a queen to the given coordinates.
	 * If add is true, it adds a queen. If it is false, it removes a queen.
	 */
	private void addQueen(int x, int y, boolean add) {
		int i;
		if (add)
			grid[x][y] = 2;
		else
			grid[x][y] = 0;
		for (i=0;i<8;i++) {
			if (i!=y) changeCell(x,i,add);
			if (i!=x) changeCell(i,y,add);
		}
		for (i=1; legal(x+i,y+i); i++)
			changeCell(x+i,y+i,add);
		for (i=1; legal(x+i,y-i); i++)
			changeCell(x+i,y-i,add);
		for (i=1; legal(x-i,y+i); i++)
			changeCell(x-i,y+i,add);
		for (i=1; legal(x-i,y-i); i++)
			changeCell(x-i,y-i,add);
		
		if (!add)
			for (i=0;i<8;i++)
				for (int j=0;j<8;j++)
					if (grid[i][j] == 2)
						addQueen(i,j,true);
	}
	
	/**
	 * Add or remove a queen to the given cell
	 */
	private void changeCell(int x, int y, boolean add) {
		if (add && grid[x][y] == 0)
			grid[x][y] = 1;
		else if (!add && grid[x][y] == 1)
			grid[x][y] = 0;
	}
	
	/**
	 * Returns true if the coordinates are a legal board position
	 */
	private boolean legal(int x, int y) {
		return (x >= 0 && x < 8 && y >= 0 && y < 8);
	}

	/**
	 * Solve the 8-queens puzzle with a very simple depth-first search.
	 */
	public boolean solve(int y) {
		int i,j;
		boolean r = false;
		
		for (i=0;i<8;i++) { 
			// for each row, try placing a queen
			if (grid[i][y] == 0) {
				addQueen(i,y,true);
				if (y == 7) {
					return true; // we have placed all queens successfully
				} else {
					if (solve(y+1)) {
						return true; // we solved it, return
					} else {
						addQueen(i,y,false); // remove the queen
					}
				}
			}
		}
		// unable to solve down this branch -- retreat!
		return false;
	}
	

}
