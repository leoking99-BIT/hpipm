/**************************************************************************************************
*                                                                                                 *
* This file is part of HPIPM.                                                                     *
*                                                                                                 *
* HPIPM -- High-Performance Interior Point Method.                                                *
* Copyright (C) 2017-2018 by Gianluca Frison.                                                     *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* This program is free software: you can redistribute it and/or modify                            *
* it under the terms of the GNU General Public License as published by                            *
* the Free Software Foundation, either version 3 of the License, or                               *
* (at your option) any later version                                                              *.
*                                                                                                 *
* This program is distributed in the hope that it will be useful,                                 *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                   *
* GNU General Public License for more details.                                                    *
*                                                                                                 *
* You should have received a copy of the GNU General Public License                               *
* along with this program.  If not, see <https://www.gnu.org/licenses/>.                          *
*                                                                                                 *
* The authors designate this particular file as subject to the "Classpath" exception              *
* as provided by the authors in the LICENSE file that accompained this code.                      *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/



void OCP_QP_DIM_PRINT(struct OCP_QP_DIM *qp_dim)
	{
	int ii;

	int N   = qp_dim->N;
	int *nx = qp_dim->nx;
	int *nu = qp_dim->nu;
	int *nbx = qp_dim->nbx;
	int *nbu = qp_dim->nbu;
	int *ng = qp_dim->ng;
	int *nsbx = qp_dim->nsbx;
	int *nsbu = qp_dim->nsbu;
	int *nsg = qp_dim->nsg;

	printf("N = %d\n\n", N);

	printf("nx =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", nx[ii]);
	printf("\n\n");

	printf("nu =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", nu[ii]);
	printf("\n\n");

	printf("nbx =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", nbx[ii]);
	printf("\n\n");

	printf("nbu =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", nbu[ii]);
	printf("\n\n");

	printf("ng =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", ng[ii]);
	printf("\n\n");

	printf("nsbx =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", nsbx[ii]);
	printf("\n\n");

	printf("nsbu =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", nsbu[ii]);
	printf("\n\n");

	printf("nsg =\n");
	for (ii = 0; ii <= N; ii++)
		printf("\t%d", nsg[ii]);
	printf("\n\n");

	return;
	}



void OCP_QP_DIM_CODEGEN(char *file_name, char *mode, char *target, struct OCP_QP_DIM *qp_dim)
	{
		int ii;

		FILE *file = fopen(file_name, mode);

		int N   = qp_dim->N;
		int *nx = qp_dim->nx;
		int *nu = qp_dim->nu;
		int *nbx = qp_dim->nbx;
		int *nbu = qp_dim->nbu;
		int *ng = qp_dim->ng;
		int *nsbx = qp_dim->nsbx;
		int *nsbu = qp_dim->nsbu;
		int *nsg = qp_dim->nsg;

		if (hpipm_strcmp(target, "C"))
		{

			fprintf(file, "/***************\n* dim\n***************/\n");

			// N
			fprintf(file, "/* N */\n");
			fprintf(file, "int N = %d;\n", N);
			// nx
			fprintf(file, "/* nx */\n");
			fprintf(file, "static int nnx[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nx[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nx = nnx;\n");
			// nu
			fprintf(file, "/* nu */\n");
			fprintf(file, "static int nnu[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nu[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nu = nnu;\n");
			// nbx
			fprintf(file, "/* nbx */\n");
			fprintf(file, "static int nnbx[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nbx[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nbx = nnbx;\n");
			// nbu
			fprintf(file, "/* nbu */\n");
			fprintf(file, "static int nnbu[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nbu[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nbu = nnbu;\n");
			// ng
			fprintf(file, "/* ng */\n");
			fprintf(file, "static int nng[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", ng[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *ng = nng;\n");
			// nsbx
			fprintf(file, "/* nsbx */\n");
			fprintf(file, "static int nnsbx[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nsbx[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nsbx = nnsbx;\n");
			// nsbu
			fprintf(file, "/* nsbu */\n");
			fprintf(file, "static int nnsbu[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nsbu[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nsbu = nnsbu;\n");
			// nsg
			fprintf(file, "/* nsg */\n");
			fprintf(file, "static int nnsg[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nsg[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nsg = nnsg;\n");

			fclose(file);

		} else if (hpipm_strcmp(target, "MATLAB"))
		{

			fprintf(file, "%**************\n%* dim\n%**************\n");

			// N
			fprintf(file, "% N \n");
			fprintf(file, "N = %d\n", N);
			// nx
			fprintf(file, "/* nx */\n");
			fprintf(file, "static int nnx[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nx[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nx = nnx;\n");
			// nu
			fprintf(file, "/* nu */\n");
			fprintf(file, "static int nnu[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nu[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nu = nnu;\n");
			// nbx
			fprintf(file, "/* nbx */\n");
			fprintf(file, "static int nnbx[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nbx[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nbx = nnbx;\n");
			// nbu
			fprintf(file, "/* nbu */\n");
			fprintf(file, "static int nnbu[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nbu[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nbu = nnbu;\n");
			// ng
			fprintf(file, "/* ng */\n");
			fprintf(file, "static int nng[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", ng[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *ng = nng;\n");
			// nsbx
			fprintf(file, "/* nsbx */\n");
			fprintf(file, "static int nnsbx[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nsbx[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nsbx = nnsbx;\n");
			// nsbu
			fprintf(file, "/* nsbu */\n");
			fprintf(file, "static int nnsbu[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nsbu[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nsbu = nnsbu;\n");
			// nsg
			fprintf(file, "/* nsg */\n");
			fprintf(file, "static int nnsg[] = {");
			for(ii=0; ii<=N; ii++)
				fprintf(file, "%d, ", nsg[ii]);
			fprintf(file, "};\n");
			fprintf(file, "int *nsg = nnsg;\n");

			fclose(file);

		} else 
		{
			printf("No valid code-generation target provided. Valid options are: C, MATLAB. Exiting.\n");
			return;
		}
		return;
	}




void OCP_QP_PRINT(struct OCP_QP_DIM *dim, struct OCP_QP *qp)
	{
	int ii;

	int N   = dim->N;
	int *nx = dim->nx;
	int *nu = dim->nu;
	int *nb = dim->nb;
	int *ng = dim->ng;
	int *ns = dim->ns;

	printf("BAt =\n");
	for (ii = 0; ii < N; ii++)
		BLASFEO_PRINT_MAT(nu[ii]+nx[ii], nx[ii+1], qp->BAbt+ii, 0, 0);

	printf("b =\n");
	for (ii = 0; ii < N; ii++)
		BLASFEO_PRINT_TRAN_VEC(nx[ii+1], qp->b+ii, 0);

	printf("RSQ =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_MAT(nu[ii]+nx[ii], nu[ii]+nx[ii], qp->RSQrq+ii, 0, 0);

	printf("Z =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_TRAN_VEC(2*ns[ii], qp->Z+ii, 0);

	printf("rqz =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_TRAN_VEC(nu[ii]+nx[ii]+ns[ii], qp->rqz+ii, 0);

	printf("idxb = \n");
	for (ii = 0; ii <= N; ii++)
		int_print_mat(1, nb[ii], qp->idxb[ii], 1);

	printf("d =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_TRAN_VEC(2*nb[ii]+2*ng[ii]+2*ns[ii], qp->d+ii, 0);

	printf("DCt =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_MAT(nu[ii]+nx[ii], ng[ii], qp->DCt+ii, 0, 0);

	printf("m =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_TRAN_VEC(2*nb[ii]+2*ng[ii]+2*ns[ii], qp->m+ii, 0);

	return;
	}



void OCP_QP_CODEGEN(char *file_name, char *mode, struct OCP_QP_DIM *dim, struct OCP_QP *qp)
	{
	int nn, ii, jj;

	FILE *file = fopen(file_name, mode);

	int N   = dim->N;
	int *nx = dim->nx;
	int *nu = dim->nu;
	int *nb = dim->nb;
	int *ng = dim->ng;
	int *ns = dim->ns;

	fprintf(file, "/***************\n* qp\n***************/\n");

	// A
	fprintf(file, "/* A */\n");
	for(nn=0; nn<N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double A%d[] = {", nn);
#else
		fprintf(file, "static float A%d[] = {", nn);
#endif
		for(ii=0; ii<nx[nn]; ii++)
			{
			for(jj=0; jj<nx[nn+1]; jj++)
				{
#ifdef DOUBLE_PRECISION
				fprintf(file, "%18.15e, ", BLASFEO_DMATEL(qp->BAbt+nn, nu[nn]+ii, jj));
#else
				fprintf(file, "%18.15e, ", BLASFEO_SMATEL(qp->BAbt+nn, nu[nn]+ii, jj));
#endif
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *AA[] = {");
#else
	fprintf(file, "static float *AA[] = {");
#endif
	for(nn=0; nn<N; nn++)
		fprintf(file, "A%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hA = AA;\n");
#else
	fprintf(file, "float **hA = AA;\n");
#endif

	// B
	fprintf(file, "/* B */\n");
	for(nn=0; nn<N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double B%d[] = {", nn);
#else
		fprintf(file, "static float B%d[] = {", nn);
#endif
		for(ii=0; ii<nu[nn]; ii++)
			{
			for(jj=0; jj<nx[nn+1]; jj++)
				{
#ifdef DOUBLE_PRECISION
				fprintf(file, "%18.15e, ", BLASFEO_DMATEL(qp->BAbt+nn, ii, jj));
#else
				fprintf(file, "%18.15e, ", BLASFEO_SMATEL(qp->BAbt+nn, ii, jj));
#endif
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *BB[] = {");
#else
	fprintf(file, "static float *BB[] = {");
#endif
	for(nn=0; nn<N; nn++)
		fprintf(file, "B%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hB = BB;\n");
#else
	fprintf(file, "float **hB = BB;\n");
#endif

	// b
	fprintf(file, "/* b */\n");
	for(nn=0; nn<N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double b%d[] = {", nn);
#else
		fprintf(file, "static float b%d[] = {", nn);
#endif
		for(jj=0; jj<nx[nn+1]; jj++)
			{
#ifdef DOUBLE_PRECISION
			fprintf(file, "%18.15e, ", BLASFEO_DVECEL(qp->b+nn, jj));
#else
			fprintf(file, "%18.15e, ", BLASFEO_SVECEL(qp->b+nn, jj));
#endif
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *bb[] = {");
#else
	fprintf(file, "static float *bb[] = {");
#endif
	for(nn=0; nn<N; nn++)
		fprintf(file, "b%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hb = bb;\n");
#else
	fprintf(file, "float **hb = bb;\n");
#endif

	// Q
	fprintf(file, "/* Q */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double Q%d[] = {", nn);
#else
		fprintf(file, "static float Q%d[] = {", nn);
#endif
		for(jj=0; jj<nx[nn]; jj++)
			{
			for(ii=0; ii<nx[nn]; ii++)
				{
#ifdef DOUBLE_PRECISION
				fprintf(file, "%18.15e, ", BLASFEO_DMATEL(qp->RSQrq+nn, nu[nn]+ii, nu[nn]+jj));
#else
				fprintf(file, "%18.15e, ", BLASFEO_SMATEL(qp->RSQrq+nn, nu[nn]+ii, nu[nn]+jj));
#endif
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *QQ[] = {");
#else
	fprintf(file, "static float *QQ[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "Q%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hQ = QQ;\n");
#else
	fprintf(file, "float **hQ = QQ;\n");
#endif

	// S
	fprintf(file, "/* S */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double S%d[] = {", nn);
#else
		fprintf(file, "static float S%d[] = {", nn);
#endif
		for(ii=0; ii<nx[nn]; ii++)
			{
			for(jj=0; jj<nu[nn]; jj++)
				{
#ifdef DOUBLE_PRECISION
				fprintf(file, "%18.15e, ", BLASFEO_DMATEL(qp->RSQrq+nn, nu[nn]+ii, jj));
#else
				fprintf(file, "%18.15e, ", BLASFEO_SMATEL(qp->RSQrq+nn, nu[nn]+ii, jj));
#endif
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *SS[] = {");
#else
	fprintf(file, "static float *SS[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "S%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hS = SS;\n");
#else
	fprintf(file, "float **hS = SS;\n");
#endif

	// R
	fprintf(file, "/* R */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double R%d[] = {", nn);
#else
		fprintf(file, "static float R%d[] = {", nn);
#endif
		for(jj=0; jj<nu[nn]; jj++)
			{
			for(ii=0; ii<nu[nn]; ii++)
				{
#ifdef DOUBLE_PRECISION
				fprintf(file, "%18.15e, ", BLASFEO_DMATEL(qp->RSQrq+nn, ii, jj));
#else
				fprintf(file, "%18.15e, ", BLASFEO_SMATEL(qp->RSQrq+nn, ii, jj));
#endif
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *RR[] = {");
#else
	fprintf(file, "static float *RR[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "R%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hR = RR;\n");
#else
	fprintf(file, "float **hR = RR;\n");
#endif

	// r
	fprintf(file, "/* r */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double r%d[] = {", nn);
#else
		fprintf(file, "static float r%d[] = {", nn);
#endif
		for(jj=0; jj<nu[nn]; jj++)
			{
#ifdef DOUBLE_PRECISION
			fprintf(file, "%18.15e, ", BLASFEO_DVECEL(qp->rqz+nn, jj));
#else
			fprintf(file, "%18.15e, ", BLASFEO_SVECEL(qp->rqz+nn, jj));
#endif
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *rr[] = {");
#else
	fprintf(file, "static float *rr[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "r%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hr = rr;\n");
#else
	fprintf(file, "float **hr = rr;\n");
#endif

	// q
	fprintf(file, "/* q */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double q%d[] = {", nn);
#else
		fprintf(file, "static float q%d[] = {", nn);
#endif
		for(jj=0; jj<nx[nn]; jj++)
			{
#ifdef DOUBLE_PRECISION
			fprintf(file, "%18.15e, ", BLASFEO_DVECEL(qp->rqz+nn, nu[nn]+jj));
#else
			fprintf(file, "%18.15e, ", BLASFEO_SVECEL(qp->rqz+nn, nu[nn]+jj));
#endif
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *qq[] = {");
#else
	fprintf(file, "static float *qq[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "q%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hq = qq;\n");
#else
	fprintf(file, "float **hq = qq;\n");
#endif

	// idxbu
	fprintf(file, "/* idxbu */\n");
	for(nn=0; nn<=N; nn++)
		{
		fprintf(file, "static int idxbu%d[] = {", nn);
		for(jj=0; jj<nb[nn]; jj++)
			{
			if(qp->idxb[nn][jj]<nu[nn])
				{
				fprintf(file, "%d, ", qp->idxb[nn][jj]);
				}
			}
		fprintf(file, "};\n");
		}
	fprintf(file, "static int *iidxbu[] = {");
	for(nn=0; nn<=N; nn++)
		fprintf(file, "idxbu%d, ", nn);
	fprintf(file, "};\n");
	fprintf(file, "int **hidxbu = iidxbu;\n");

	// lbu
	fprintf(file, "/* lbu */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double lbu%d[] = {", nn);
#else
		fprintf(file, "static float lbu%d[] = {", nn);
#endif
		for(jj=0; jj<nb[nn]; jj++)
			{
			if(qp->idxb[nn][jj]<nu[nn])
				{
				fprintf(file, "%18.15e, ", BLASFEO_DVECEL(qp->d+nn, jj));
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *llbu[] = {");
#else
	fprintf(file, "static float *llbu[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "lbu%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hlbu = llbu;\n");
#else
	fprintf(file, "float **hlbu = llbu;\n");
#endif

	// ubu
	fprintf(file, "/* ubu */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double ubu%d[] = {", nn);
#else
		fprintf(file, "static float ubu%d[] = {", nn);
#endif
		for(jj=0; jj<nb[nn]; jj++)
			{
			if(qp->idxb[nn][jj]<nu[nn])
				{
				fprintf(file, "%18.15e, ", -BLASFEO_DVECEL(qp->d+nn, nb[nn]+ng[nn]+jj));
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *uubu[] = {");
#else
	fprintf(file, "static float *uubu[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "ubu%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hubu = uubu;\n");
#else
	fprintf(file, "float **hubu = uubu;\n");
#endif

	// idxbx
	fprintf(file, "/* idxbx */\n");
	for(nn=0; nn<=N; nn++)
		{
		fprintf(file, "static int idxbx%d[] = {", nn);
		for(jj=0; jj<nb[nn]; jj++)
			{
			if(qp->idxb[nn][jj]>=nu[nn])
				{
				fprintf(file, "%d, ", qp->idxb[nn][jj]-nu[nn]);
				}
			}
		fprintf(file, "};\n");
		}
	fprintf(file, "static int *iidxbx[] = {");
	for(nn=0; nn<=N; nn++)
		fprintf(file, "idxbx%d, ", nn);
	fprintf(file, "};\n");
	fprintf(file, "int **hidxbx = iidxbx;\n");

	// lbx
	fprintf(file, "/* lbx */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double lbx%d[] = {", nn);
#else
		fprintf(file, "static float lbx%d[] = {", nn);
#endif
		for(jj=0; jj<nb[nn]; jj++)
			{
			if(qp->idxb[nn][jj]>=nu[nn])
				{
				fprintf(file, "%18.15e, ", BLASFEO_DVECEL(qp->d+nn, jj));
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *llbx[] = {");
#else
	fprintf(file, "static float *llbx[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "lbx%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hlbx = llbx;\n");
#else
	fprintf(file, "float **hlbx = llbx;\n");
#endif

	// ubx
	fprintf(file, "/* ubx */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double ubx%d[] = {", nn);
#else
		fprintf(file, "static float ubx%d[] = {", nn);
#endif
		for(jj=0; jj<nb[nn]; jj++)
			{
			if(qp->idxb[nn][jj]>=nu[nn])
				{
				fprintf(file, "%18.15e, ", -BLASFEO_DVECEL(qp->d+nn, nb[nn]+ng[nn]+jj));
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *uubx[] = {");
#else
	fprintf(file, "static float *uubx[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "ubx%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hubx = uubx;\n");
#else
	fprintf(file, "float **hubx = uubx;\n");
#endif

	// C
	fprintf(file, "/* C */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double C%d[] = {", nn);
#else
		fprintf(file, "static float C%d[] = {", nn);
#endif
		for(ii=0; ii<nx[nn]; ii++)
			{
			for(jj=0; jj<ng[nn]; jj++)
				{
#ifdef DOUBLE_PRECISION
				fprintf(file, "%18.15e, ", BLASFEO_DMATEL(qp->DCt+nn, nu[nn]+ii, jj));
#else
				fprintf(file, "%18.15e, ", BLASFEO_SMATEL(qp->DCt+nn, nu[nn]+ii, jj));
#endif
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *CC[] = {");
#else
	fprintf(file, "static float *CC[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "C%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hC = CC;\n");
#else
	fprintf(file, "float **hC = CC;\n");
#endif

	// D
	fprintf(file, "/* D */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double D%d[] = {", nn);
#else
		fprintf(file, "static float D%d[] = {", nn);
#endif
		for(ii=0; ii<nu[nn]; ii++)
			{
			for(jj=0; jj<ng[nn]; jj++)
				{
#ifdef DOUBLE_PRECISION
				fprintf(file, "%18.15e, ", BLASFEO_DMATEL(qp->DCt+nn, ii, jj));
#else
				fprintf(file, "%18.15e, ", BLASFEO_SMATEL(qp->DCt+nn, ii, jj));
#endif
				}
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *DD[] = {");
#else
	fprintf(file, "static float *DD[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "D%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hD = DD;\n");
#else
	fprintf(file, "float **hD = DD;\n");
#endif

	// lg
	fprintf(file, "/* lg */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double lg%d[] = {", nn);
#else
		fprintf(file, "static float lg%d[] = {", nn);
#endif
		for(jj=0; jj<ng[nn]; jj++)
			{
			fprintf(file, "%18.15e, ", BLASFEO_DVECEL(qp->d+nn, nb[nn]+jj));
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *llg[] = {");
#else
	fprintf(file, "static float *llg[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "lg%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hlg = llg;\n");
#else
	fprintf(file, "float **hlg = llg;\n");
#endif

	// ug
	fprintf(file, "/* ug */\n");
	for(nn=0; nn<=N; nn++)
		{
#ifdef DOUBLE_PRECISION
		fprintf(file, "static double ug%d[] = {", nn);
#else
		fprintf(file, "static float ug%d[] = {", nn);
#endif
		for(jj=0; jj<ng[nn]; jj++)
			{
			fprintf(file, "%18.15e, ", -BLASFEO_DVECEL(qp->d+nn, 2*nb[nn]+ng[nn]+jj));
			}
		fprintf(file, "};\n");
		}
#ifdef DOUBLE_PRECISION
	fprintf(file, "static double *uug[] = {");
#else
	fprintf(file, "static float *uug[] = {");
#endif
	for(nn=0; nn<=N; nn++)
		fprintf(file, "ug%d, ", nn);
	fprintf(file, "};\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hug = uug;\n");
#else
	fprintf(file, "float **hug = uug;\n");
#endif

	// Zl
	fprintf(file, "/* Zl */\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hZl;\n");
#else
	fprintf(file, "float **hZl;\n");
#endif

	// Zu
	fprintf(file, "/* Zu */\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hZu;\n");
#else
	fprintf(file, "float **hZu;\n");
#endif

	// zl
	fprintf(file, "/* zl */\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hzl;\n");
#else
	fprintf(file, "float **hzl;\n");
#endif

	// zu
	fprintf(file, "/* zu */\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hzu;\n");
#else
	fprintf(file, "float **hzu;\n");
#endif

	// idxs
	fprintf(file, "/* idxs */\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hidxs;\n");
#else
	fprintf(file, "float **hidxs;\n");
#endif

	// lls
	fprintf(file, "/* lls */\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hlls;\n");
#else
	fprintf(file, "float **hlls;\n");
#endif

	// lus
	fprintf(file, "/* lus */\n");
#ifdef DOUBLE_PRECISION
	fprintf(file, "double **hlus;\n");
#else
	fprintf(file, "float **hlus;\n");
#endif

	// XXX what follows is not part of the QP !!!

	// u_guess
//	fprintf(file, "/* u_guess */\n");
//	fprintf(file, "double **hu_guess;\n");

	// x_guess
//	fprintf(file, "/* x_guess */\n");
//	fprintf(file, "double **hx_guess;\n");

	// sl_guess
//	fprintf(file, "/* sl_guess */\n");
//	fprintf(file, "double **hsl_guess;\n");

	// su_guess
//	fprintf(file, "/* su_guess */\n");
//	fprintf(file, "double **hsu_guess;\n");

	fclose(file);

	return;
	}



void OCP_QP_SOL_PRINT(struct OCP_QP_DIM *qp_dim, struct OCP_QP_SOL *qp_sol)
	{
	int ii;

	int N   = qp_dim->N;
	int *nx = qp_dim->nx;
	int *nu = qp_dim->nu;
	int *nb = qp_dim->nb;
	int *ng = qp_dim->ng;
	int *ns = qp_dim->ns;

	printf("uxs =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_TRAN_VEC(nu[ii] + nx[ii] + 2 * ns[ii], &qp_sol->ux[ii], 0);

	printf("pi =\n");
	for (ii = 0; ii < N; ii++)
		BLASFEO_PRINT_TRAN_VEC(nx[ii + 1], &qp_sol->pi[ii], 0);

	printf("lam =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_TRAN_VEC(2 * nb[ii] + 2 * ng[ii] + 2 * ns[ii], &qp_sol->lam[ii], 0);

	printf("t =\n");
	for (ii = 0; ii <= N; ii++)
		BLASFEO_PRINT_TRAN_VEC(2 * nb[ii] + 2 * ng[ii] + 2 * ns[ii], &qp_sol->t[ii], 0);

	return;
	}



void OCP_QP_IPM_ARG_CODEGEN(char *file_name, char *mode, struct OCP_QP_DIM *qp_dim, struct OCP_QP_IPM_ARG *arg)
	{
	int ii;

	FILE *file = fopen(file_name, mode);

	fprintf(file, "/***************\n* arg\n***************/\n");

	// iter_max
	fprintf(file, "/* mode */\n");
	fprintf(file, "int mode = %d;\n", arg->mode);
	// iter_max
	fprintf(file, "/* iter_max */\n");
	fprintf(file, "int iter_max = %d;\n", arg->iter_max);
	// alpha_min
	fprintf(file, "/* alpha_min */\n");
	fprintf(file, "double alpha_min = %18.15e;\n", arg->alpha_min);
	// mu0
	fprintf(file, "/* mu0 */\n");
	fprintf(file, "double mu0 = %18.15e;\n", arg->mu0);
	// tol_stat
	fprintf(file, "/* tol_stat */\n");
	fprintf(file, "double tol_stat = %18.15e;\n", arg->res_g_max);
	// tol_eq
	fprintf(file, "/* tol_eq */\n");
	fprintf(file, "double tol_eq = %18.15e;\n", arg->res_b_max);
	// tol_ineq
	fprintf(file, "/* tol_ineq */\n");
	fprintf(file, "double tol_ineq = %18.15e;\n", arg->res_d_max);
	// tol_comp
	fprintf(file, "/* tol_comp */\n");
	fprintf(file, "double tol_comp = %18.15e;\n", arg->res_m_max);
	// reg_prim
	fprintf(file, "/* reg_prim */\n");
	fprintf(file, "double reg_prim = %18.15e;\n", arg->reg_prim);
	// warm_start
	fprintf(file, "/* warm_start */\n");
	fprintf(file, "int warm_start = %d;\n", arg->warm_start);
	// pred_corr
	fprintf(file, "/* pred_corr */\n");
	fprintf(file, "int pred_corr = %d;\n", arg->pred_corr);
	// ric_alg
	fprintf(file, "/* ric_alg */\n");
	fprintf(file, "int ric_alg = %d;\n", arg->square_root_alg);

	fclose(file);

	return;
	}

