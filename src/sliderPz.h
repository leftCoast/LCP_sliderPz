#ifndef slider_h
#define slider_h

#include <lilOS.h> 
#include <cardIndex.h>
#include <sliderPuzzleBits.h>	

//
// Little apology here. This game wasn't so much designed, as just hacked into existence
// with little to no thought to design at all. So it's kinda' a mess, and hard to add
// features to. There are a lot of features I'd like to add.
//
// The other thing is. No one can ever seem to solve the damn puzzles. With the exception
// of Shelby's boyfriend the mega-athlete man. Zip zip zip, all done! Go figure. Are the
// rest of us all too highly trained?
//
// Anyway it works. And, if you don't know what features I wanted to add, you'll never
// miss 'em.
//
// Have fun with it!
//


class sliderPz;



class nextImage : public iconButton {

	public:
				nextImage(int inX,int inY,const char* path);
				~nextImage(void);
				
				void	setGame(sliderPz* inPtr);
	virtual	void  doAction(void);
	
				sliderPz* ourGame;
};



class scramble : public iconButton {

	public:
				scramble(int inX,int inY,const char* path);
				~scramble(void);
				
				void	setGame(sliderPz* inPtr);
	virtual	void  doAction(void);
	
				sliderPz* ourGame;
};


// pixFileItem


class pixFileItem : public linkListObj {

	public:
		pixFileItem(const char* inName);
		~pixFileItem(void);
		
		char*	getName(void);
		
		char*	fileName;
};

// pixIndex

class pixIndex : public linkList {

	public:
				pixIndex(void);
	virtual	~pixIndex(void);
	
				bool	isPixFile(const char* fileName);
				void	buildList(filePath* imagePath);
				char*	getName(int cardIndex);
};



class sliderPz :  public panel {

	public:
				sliderPz(int ourAppID);
	virtual	~sliderPz(void);
          
	virtual	void	setup(void);
				
				void	buildPixIndex(void);
				bool	setImagePath(void);
				bool	chooseImage(void);
	virtual	void	drawSelf(void);
				void	doScramble(void);
	virtual	void	loop(void);
	virtual	void	closing(void);
	
	sliderBoard*	ourBoard;		// Our game board.
	pixIndex			ourPixIndex;	// Our list of image file names.
	cardIndex*		ourCardDeck;	// Our list deck of image ID's.
	filePath			ourImagePath;	// We build the path to our image here.	  
};


#endif
