/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
** Copyright (c) 2005, Monash Cluster Computing 
** All rights reserved.
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** 		* Redistributions of source code must retain the above copyright notice, 
** 			this list of conditions and the following disclaimer.
** 		* Redistributions in binary form must reproduce the above copyright 
**			notice, this list of conditions and the following disclaimer in the 
**			documentation and/or other materials provided with the distribution.
** 		* Neither the name of the Monash University nor the names of its contributors 
**			may be used to endorse or promote products derived from this software 
**			without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
** PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS 
** BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
** CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
** SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
** LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT 
** OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**
** Contact:
*%		Louis Moresi - Louis.Moresi@sci.monash.edu.au
*%
** Contributors:
*+		Robert Turnbull
*+		Vincent Lemiale
*+		Louis Moresi
*+		David May
*+		David Stegman
*+		Mirko Velic
*+		Patrick Sunter
*+		Julian Giordani
*+
** $Id: Lava.h 354 2010-12-06 08:19:27Z Echoi $
** 
**~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef __Underworld_Rheology_Lava_h__
#define __Underworld_Rheology_Lava_h__

/** Textual name of this class - This is a global pointer which is used for times when you need to refer to class and not a particular instance of a class */
extern const Type Lava_Type;

		
/** Rheology class contents - this is defined as a macro so that sub-classes of this class can use this macro at the start of the definition of their struct */
#define __Lava															\
	/* Macro defining parent goes here - This means you can cast this class as its parent */ \
	__Rheology															\
	/* Virtual functions go here */										\
	/* Material Parameters */											\
	FeVariable*                                         strainRateInvField;	\
	FeVariable*                                         temperatureField; \
	double                                              eta0;			\
	double                                              theta;			\
	double                                              maxVis; 

struct Lava { __Lava };
	
/** Private Constructor: This will accept all the virtual functions for this class as arguments. */
	
#ifndef ZERO
#define ZERO 0
#endif

#define LAVA_DEFARGS					\
	RHEOLOGY_DEFARGS

#define LAVA_PASSARGS					\
	RHEOLOGY_PASSARGS

Lava* _Lava_New(  LAVA_DEFARGS  );

/* 'Stg_Component' implementations */

void* _Lava_DefaultNew( Name name ) ;
void _Lava_AssignFromXML( void* rheology, Stg_ComponentFactory* cf, void* data );
void _Lava_Destroy( void* rheology, void* data );
void _Lava_Init( Lava* self, FeVariable* strainRateInvField, FeVariable* temperatureField, double eta0, double theta, double maxVis );
/* void _Lava_Build( void* _self, void* data ); */
/* void _Lava_Initialise( void* _self, void* data ); */

   
void _Lava_ModifyConstitutiveMatrix( 
									void*                                              rheology, 
									ConstitutiveMatrix*                                constitutiveMatrix,
									MaterialPointsSwarm*                               swarm,
									Element_LocalIndex                                 lElement_I,
									MaterialPoint*                                     materialPoint,
									Coord                                              xi );
#endif

