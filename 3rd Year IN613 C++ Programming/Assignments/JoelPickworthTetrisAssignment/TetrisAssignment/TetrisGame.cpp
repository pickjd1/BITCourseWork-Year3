#include "StdAfx.h"
#include "TetrisGame.h"

TetrisGame::TetrisGame(Graphics^ startCanvas, Random^ startRGen)
{

	canvas = startCanvas;
	rGen = startRGen;

	bufferImage = gcnew Bitmap(600,660);

	buffer = Graphics::FromImage(bufferImage);

	grid = gcnew array<GameGrid^,2>(10,24);

	NewGame();

}

	void TetrisGame::PopulateGrid()
	{
		int y = -120;

		for (int row = 0; row < 24; row++)
		{
			int x = (bufferImage->Width /2) - 30;

			for (int col = 0; col < 10; col++)
			{
				bool visible = true;
				if (row <= 4)
				{
					visible = false;
				}

				grid[col,row] = gcnew GameGrid(row, col,x,y,visible,buffer);

				x+=30;
			}
			y+=30;
		}
	}

	void TetrisGame::NewGame()
	{
		PopulateGrid();

		currShape = GetShape();
		nextShape = GetShape();

		gravity = GRAVITY;
		count = 10;

		gravTemp = gravity;

		score = 0;
		level = 0;

		currCells = currShape->GetCells();

	}

	void TetrisGame::CheckDown()
	{
		array<bool^>^ check = gcnew array<bool^>(4);

		array <Cell^>^ temp = currShape->Down();

		for (int i = 0; i < 4; i++)
		{
			if(!(temp[i]->GetRow() >=24))
			{
				if (!grid[temp[i]->GetCol(),temp[i]->GetRow()]->GetFull())
				{
					check[i] = false;
				}
				else
				{
					check[i] = true;
				}
				
			}
			else
			{
				check[i] = true;
			}
		}

		if (check[0]->Equals(false) && check[1]->Equals(false) && check[2]->Equals(false))
		{
			currShape->SetCells(temp);
		}
		else
		{
			temp = currShape->GetCells();
			for (int i = 0; i < 4; i++)
			{
				grid[temp[i]->GetCol(), temp[i]->GetRow()]->SetFull(true);
			}

			currShape = nextShape;
			nextShape = GetShape();

			count = gravity;
		}
	}

	void TetrisGame::Update()
	{
		for (int row = 0; row < 24; row++)
		{
			for (int col = 0; col < 10; col++)
			{
				if (!grid[col,row]->GetFull())
				{
					grid[col,row]->ResetColor();
				}
			}
		}

		currCells = currShape->GetCells();

		for (int i = 0; i < 4; i++)
		{
			grid[currCells[i]->GetCol(),currCells[i]->GetRow()]->SetFillColor(currShape->GetColor());
		}
	}

	void TetrisGame::RotateCheck()
	{
		array<bool^>^ check = gcnew array<bool^>(4);
	
		array<Cell^>^ temp = currShape->Rotate();

		for (int i = 0; i < 4; i++)
		{
			
			if (!(temp[i]->GetCol() >= 10) && !(temp[i]->GetCol() < 0))
			{
				
				if (!grid[temp[i]->GetCol(),temp[i]->GetRow()]->GetFull())
				{
					check[i] = false;
				}
				else
				{
					check[i] = true;
				}
			}
			else
			{
				check[i] = true;
			}
		}

		if (check[0]->Equals(false) && check[1]->Equals(false) && check[2]->Equals(false))
		{
			currShape->SetCells(temp);
		}
	}

	void TetrisGame::MoveCheck(int dir)
	{
		array<bool^>^ check = gcnew array<bool^>(4);

		array<Cell^>^ temp = currShape->Move(dir);

		for (int i = 0; i < 4; i++)
		{
			if (!(temp[i]->GetCol() >= 10) && !(temp[i]->GetCol() < 0))
			{
				if (!grid[temp[i]->GetCol(),temp[i]->GetRow()]->GetFull())
					check[i] = false;
				else
					check[i] = true;
			}
			else
			{
				check[i] = true;
			}
		}

		if (check[0]->Equals(false) && check[1]->Equals(false) && check[2]->Equals(false))
		{
			currShape->SetCells(temp);
		}
	}

	void TetrisGame::GameOverCheck()
	{
		//Need to implement
		//if currShape->
	}

	void TetrisGame::RowCheck()
	{
		int rows = 0;
		
		for (int row = 0; row < 24; row++)
		{

			int rowFull = 0;
			for (int col = 0; col < 10; col++)
			{
				if(grid[col,row]->GetFull())
				{
					rowFull++;
				}
			}

			if (rowFull == 10)
			{
				DeleteRow(row);
				rows++;
				score++;
			}
		}
	}

	void TetrisGame::DeleteRow(int row)
	{
		for (int i = 0; i < 10; i++)
		{
			grid[i,row]->SetFull(false);
			grid[i,row]->ResetColor();
			
		}
		
		DropRow(row);

	}

	void TetrisGame::DropRow(int r)
	{
		for (int row = r; row > 0; row--)
		{
			for (int col = 0; col < 10; col++)
			{
				if (grid[col,row - 1]->GetFull())
				{
					grid[col,row]->SetFull(true);
					grid[col,row]->SetFillColor(grid[col,row - 1]->GetFillColor());
				}
				else
				{
					grid[col,row]->SetFull(false);
					grid[col,row]->ResetColor();
				}
			}
		}
	}

	void TetrisGame::Draw()
	{
		buffer->Clear(Color::DodgerBlue);

		buffer->DrawString("SCORE : " + score.ToString(),gcnew Font("Arial", 10), gcnew SolidBrush(Color::Black),
			30, 70);

		for (int row = 0; row < 24; row++)
		{
			for (int col = 0; col < 10; col++)
			{
				grid[col,row]->Draw();
			}
		}

		canvas->DrawImage(bufferImage, Point(0,0));
	}

	bool TetrisGame::CheckKeyPressed()
	{
		if (keyPressed == nullptr ||( keyPressed->KeyCode != Keys::Up && keyPressed->KeyCode != Keys::Left &&
			keyPressed->KeyCode != Keys::Right && keyPressed->KeyCode != Keys::Down))
			return false;

		return true;
	}

	void TetrisGame::Loop()
	{

		if (CheckKeyPressed()) {
			if (keyPressed->KeyCode == Keys::Up)
			{
				RotateCheck();
				keyPressed = nullptr;
			}
			else if (keyPressed->KeyCode == Keys::Left)
			{
				MoveCheck(-1);
			}
			else if (keyPressed->KeyCode == Keys::Right)
			{
				MoveCheck(1);
			}
			else if (keyPressed->KeyCode == Keys::Down)
			{
				gravTemp = gravity;
				gravity = 1;
			}

			keyPressed = nullptr;
		}

		if (count >= gravity)
		{
			CheckDown();
			GameOverCheck();
			count = 0;
		}
		
		RowCheck();
		Update();
		
		Draw();
		count++;
		gravity = gravTemp;
	}

	TetrisShape^ TetrisGame::GetShape()
	{
		switch (rGen->Next(7))
		{
		case 0:
			return gcnew Line();
		case 1:
			return gcnew S();
		case 2:
			return gcnew J();
		case 3:
			return gcnew L();
		case 4:
			return gcnew Z();
		case 5:
			return gcnew T();
		case 6:
			return gcnew Square();

		}
	}

