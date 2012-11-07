class object {

	string name;

	unsigned long long int radius;
	long double mass;
	long double x, y;
	float turnRadians;
	long double distance (long double targX, long double targY), stepDistance (long double targX, long double targY), thetaToObject (const physical_t &target);	//distance squared to point, distance squared next cycle, theta between physical and object

	long double acceleration;    //total acceleration, no calculations are actually performed on this, just for printing purposes
	void acc (long double force, long double radians),	//just calls accX and accY, and converts from m/s/ms to m/s/s
	accX (long double force, long double radians), accY (long double force, long double radians);
	long double Vx, Vy, V(), thetaV();   //the physical's speed (m/s) along each axis and magnitude/theta of velocity vector
	long double Vcen (const physical_t &targ), Vtan (const physical_t &targ), Vtarg (long double targV);	//gets the vcen and vtan relative to a target, and velocity relative to target
	long double orbitV (const physical_t &targ);	//calculates the relative velocity needed to orbit at current height around target, NOT TAKING INTO ACCOUNT MASS OF CALLING PHYSICAL
	long double gravity (long double targX, long double targY, long double targMass);  //calculate gravitational acceleration to object
	long double apoapsis, periapsis;	//stores periapsis and apoapsis around targ, updated by calling eccentricity
	void eccentricity (physical_t &targ);	//eccentricity of orbit around object NOT ACCOUNTING FOR MASS OF CALLING PHYSICAL
	void gravitate (physical_t &targ), detectCollision (physical_t &targ);  //gravitate towards/detect collision with target

	void turn();   //turns the physical
	long double turnRate; //rate at which the physical turns
	float turnRateStep, maxTurnRate;    //values are in degrees per second

	unsigned fillColor;
	virtual void draw (unsigned A, unsigned B, long double zoom);	//draws physical

	struct AI_t {

		navmode_enum navmode;       //enum for which navmode to use, e.g. MAN, CCW
		string descriptor[NAVMAX];   //string describing the current nav mode

		AI_t () :
			navmode (MAN) {

			descriptor[MAN] = "Manual";
			descriptor[APP_TARG] = "App Targ";
			descriptor[DEPART_REF] = "Depart Ref";
			descriptor[CCW] = "CCW Prograde";
			descriptor[CW] = "CW Retrograde";
		}
	} AI;

	union { //declares either engine or atmosphereHeight

		float engine;	//percentage of engines that is engaged. In orbit, and in corbit (this program) there is no upper limit, and engines can go negative
		const unsigned long long atmosphereHeight;	//height of atmosphere, in m
	};

	union { //declares either fuel or atmosphereDrag

		unsigned long fuel;	//fuel in kg
		const unsigned atmosphereDrag;	//I'm going to get around to implementing this after exams
	};

	physical_t (string _name, long double _x, long double _y, long double _Vx, long double _Vy, long double _mass, unsigned long _radius, unsigned _fillColor, float _engine_atmosphereHeight, unsigned long long int _fuel_atmosphereDrag) :
		name (_name), x (_x), y (_y), Vx (_Vx), Vy (_Vy), mass (_mass), radius (_radius), fillColor (_fillColor), turnRate (0), turnRadians (3.1), atmosphereHeight (_engine_atmosphereHeight), atmosphereDrag (_fuel_atmosphereDrag), turnRateStep (0.5 * Pi / 180), maxTurnRate (41.5 * Pi / 180) {
	}
};


struct solarBody_t : physical_t {   //stores information about an astronomical body, in addition to information already stored by an physical

	const unsigned atmosphereColor;	//color of atmosphere

	virtual void draw(unsigned A, unsigned B, long double zoom);	//draws planet with atmosphere

	solarBody_t (string _name, long double _x, long double _y, long double _Vx, long double _Vy, long double _mass, unsigned long _radius, unsigned _fillColor, unsigned _atmosphereColor, unsigned long long int _atmosphereHeight, unsigned long _atmosphereDrag) :
		physical_t (_name, _x, _y, _Vx, _Vy, _mass, _radius, _fillColor, _atmosphereHeight, _atmosphereDrag),
		atmosphereColor (_atmosphereColor) {

		cout << "\n" << name << " initialized, with data of\n";
		cout << "x = " << x << "\n";
		cout << "y = " << y << "\n";
		cout << "Vx = " << Vx << "\n";
		cout << "Vy = " << Vy << "\n";
		cout << "mass = " << mass << "\n";
		cout << "radius = " << radius << "\n";
		cout << hex << "fillColor = " << fillColor << "\n";
		cout << "atmosphereColor = " << atmosphereColor << "\n";
		cout << "atmosphereHeight = " << dec << atmosphereHeight << "\n";
		cout << "atmosphereDrag = " << atmosphereDrag << "\n";
	}
};

struct ship_t : physical_t {  //stores information about a pilotable ship, in addition to information already stored by an physical

	void move(), fireEngine();	//updated move function, includes fireEngine, which fires engines
	long double totalMass();	//finds eccentricity of orbit around target, NOT accounting for other objects

	const unsigned engineColor;	//color of engine
	const unsigned short engineRadius;
	const float enginePower, burnRate;	//how powerful an engine is, in m/s/s, and how much fuel it burns

	virtual void draw(unsigned A, unsigned B, long double zoom);	//draws a circle with a line pointing the direction the ship is facing

	ship_t (string _name, long double _x, long double _y, long double _Vx, long double _Vy, long double _mass, unsigned long _radius, unsigned _fillColor, unsigned _engineColor, unsigned short _engineRadius, unsigned long _fuel) :
		physical_t (_name, _x, _y, _Vx, _Vy, _mass, _radius, _fillColor, 0, _fuel),
		engineColor (_engineColor), engineRadius (_engineRadius), enginePower (1e6), burnRate (.0444) {
	}
};


struct habitat_t : ship_t {

	void draw(unsigned A, unsigned B, long double zoom);	//draws habitat

	habitat_t (string _name, long double _x, long double _y, long double _Vx, long double _Vy, long double _mass, unsigned long _radius, unsigned _fillColor, unsigned _engineColor, unsigned short _engineRadius, unsigned long _fuel) :
		ship_t (_name, _x, _y, _Vx, _Vy, _mass, _radius, _fillColor, _engineColor, _engineRadius, _fuel) {

		cout << "\n" << name << " initialized, with data of\n";
		cout << "x = " << x << "\n";
		cout << "y = " << y << "\n";
		cout << "Vx = " << Vx << "\n";
		cout << "Vy = " << Vy << "\n";
		cout << "mass = " << mass << "\n";
		cout << "radius = " << radius << "\n";
		cout << hex << "fillColor = " << fillColor << "\n";
		cout << "engineColor = " << engineColor << "\n";
		cout << "engineRadius = " << dec << engineRadius << "\n";
		cout << "fuel = " << fuel << "\n";
	}
};
