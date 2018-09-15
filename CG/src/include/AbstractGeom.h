#ifndef ABSTRACTGEOM_H
#define ABSTRACTGEOM_H

class AbstractGeom
{
  public:
	AbstractGeom();
	AbstractGeom(float x, float y, float z) : posicaoX(x), posicaoY(y), posicaoZ(z){};
	~AbstractGeom();

	float GetposicaoX() { return posicaoX; }
	void SetposicaoX(float val) { posicaoX = val; }
	float GetposicaoY() { return posicaoY; }
	void SetposicaoY(float val) { posicaoY = val; }
	float GetposicaoZ() { return posicaoZ; }
	void SetposicaoZ(float val) { posicaoZ = val; }

	void addPosicaoX(float val) { posicaoX += val; }
	void addPosicaoY(float val) { posicaoY += val; }
	void addPosicaoZ(float val) { posicaoZ += val; }

	float GetalturaX() { return alturaX; }
	void SetalturaX(float val) { alturaX = val; }
	float GetalturaY() { return alturaY; }
	void SetalturaY(float val) { alturaY = val; }
	float GetalturaZ() { return alturaZ; }
	void SetalturaZ(float val) { alturaZ = val; }

	float GetalturaInicialX() { return posicaoX + alturaX; }
	float GetalturaFinalX() { return posicaoX - alturaX; }
	float GetalturaInicialY() { return posicaoY + alturaY; }
	float GetalturaFinalY() { return posicaoY - alturaY; }
	float GetalturaInicialZ() { return posicaoZ + alturaZ; }
	float GetalturaFinalZ() { return posicaoZ - alturaZ; }

	bool colisaoX(float var);
	bool colisaoY(float var);
	bool colisaoZ(float var);

	virtual bool haColisao(float x, float y, float z) { return false; }

  protected:
	float posicaoX;
	float posicaoY;
	float posicaoZ;
	float alturaX;
	float alturaY;
	float alturaZ;

  private:
};

#endif // ABSTRACTGEOM_H
