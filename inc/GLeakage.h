#ifndef _QIF_GLeakage_h_
#define _QIF_GLeakage_h_
/*
This file belongs to the LIBQIF library.
A Quantitative Information Flow C++ Toolkit Library.
Copyright (C) 2013  Universidad Nacional de Río Cuarto(National University of Río Cuarto).
Author: Martinelli Fernán - fmartinelli89@gmail.com - Universidad Nacional de Río Cuarto (Argentina)
LIBQIF Version: 1.0
Date: 12th Nov 2013 
========================================================================
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

=========================================================================
*/
#include "EntropyModel.h"
#include "LinearProgram.h"

/*! \class GLeakage
 *  \brief The Generalized Gain Function model of entropy.
 *
 *  For most information about the foundations of this theory see <a href="../papers/gleakage.pdf">here</a> 
 */
class GLeakage : public EntropyModel
{
	public:
		
		//! A normal constructor taking 2 arguments.
			/*!
			\sa ~GLeakage().
			*/
		GLeakage(Channel& c,Gain& g);
	
		//! A normal destroyer member.
			/*!
			\sa GLeakage()
			*/
//		~GLeakage();
		
		DoubleType vulnerability(Prob& pi);
			
		DoubleType cond_vulnerability(Prob& pi);
			
		DoubleType leakage(Prob& pi);
			
		DoubleType additive_leakage(Prob& pi);
		
		DoubleType entropy(Prob& pi);
			
		DoubleType cond_entropy(Prob& pi);
			
		DoubleType capacity();
		/*
		void * compare_over_prior(Channel& other_channel);
		
		void * compare_over_gain(Channel& other_channel,Prob& prior);
		*/
		virtual const char* class_name() { return "GLeakage";}
		
};
#endif
