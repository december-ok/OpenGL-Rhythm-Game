#include "MultiScene.h"
#include "NetworkSocket.h"
#include "ResultScene.h"
NetworkSocket* gameSocket;

MultiScene::MultiScene(GameWindow* window, MUSIC id)
{
	this->window = window;

	this->id = id;
	for (int i = 0; i < LINES; i++) {
		line_input[i] = 0;
	}
	switch (this->id)
	{
	case CANON:
		this->name = "Cannon Variation";
		this->artist = "Johan Pachelbel";
		this->musicFile = "./Canon.mp3";
		break;
	default:
		break;
	}
	
	this->init();
}

MultiScene::~MultiScene()
{
}

void MultiScene::init(void)
{
	gameSocket = new NetworkSocket(this);
	this->myGameInfo = new GameInfo();
	this->opponentGameInfo = new GameInfo();
	U_Config = new UserConfig();
	BASS_Init(-1, 44100, 0, 0, NULL);

	this->loadMusic();

	int s;
	float t;

	switch (this->id)
	{
		case CANON:
			this->notes[2].push_back((Note*)new SectionNote(300, 373));

			this->notes[3].push_back((Note*)new NormalNote(390));
			this->notes[1].push_back((Note*)new NormalNote(435));

			this->notes[2].push_back((Note*)new SectionNote(480, 553));

			this->notes[1].push_back((Note*)new NormalNote(570));
			this->notes[0].push_back((Note*)new NormalNote(615));

			this->notes[1].push_back((Note*)new SectionNote(660, 733));

			this->notes[3].push_back((Note*)new NormalNote(750));
			this->notes[2].push_back((Note*)new NormalNote(795));

			this->notes[3].push_back((Note*)new SectionNote(840, 913));

			this->notes[0].push_back((Note*)new NormalNote(930));
			this->notes[2].push_back((Note*)new NormalNote(936));
			this->notes[0].push_back((Note*)new NormalNote(941));
			this->notes[2].push_back((Note*)new NormalNote(947));
			this->notes[0].push_back((Note*)new NormalNote(953));
			this->notes[2].push_back((Note*)new NormalNote(958));
			this->notes[0].push_back((Note*)new NormalNote(964));
			this->notes[2].push_back((Note*)new NormalNote(969));
			this->notes[1].push_back((Note*)new NormalNote(975));
			this->notes[3].push_back((Note*)new NormalNote(981));
			this->notes[1].push_back((Note*)new NormalNote(986));
			this->notes[3].push_back((Note*)new NormalNote(992));
			this->notes[1].push_back((Note*)new NormalNote(998));
			this->notes[3].push_back((Note*)new NormalNote(1003));
			this->notes[1].push_back((Note*)new NormalNote(1009));
			this->notes[3].push_back((Note*)new NormalNote(1014));

			this->notes[0].push_back((Note*)new NormalNote(1020));
			this->notes[1].push_back((Note*)new NormalNote(1043));
			this->notes[3].push_back((Note*)new NormalNote(1065));

			this->notes[2].push_back((Note*)new NormalNote(1110));
			this->notes[1].push_back((Note*)new NormalNote(1155));

			this->notes[0].push_back((Note*)new NormalNote(1200));
			this->notes[1].push_back((Note*)new NormalNote(1245));

			this->notes[2].push_back((Note*)new NormalNote(1290));

			this->notes[1].push_back((Note*)new NormalNote(1380));
			this->notes[0].push_back((Note*)new NormalNote(1425));

			this->notes[2].push_back((Note*)new NormalNote(1470));
			this->notes[1].push_back((Note*)new NormalNote(1515));

			this->notes[0].push_back((Note*)new NormalNote(1560));
			this->notes[3].push_back((Note*)new NormalNote(1605));

			this->notes[1].push_back((Note*)new NormalNote(1650));
			this->notes[0].push_back((Note*)new NormalNote(1695));
			this->notes[3].push_back((Note*)new NormalNote(1718));

			this->notes[0].push_back((Note*)new NormalNote(1740));
			this->notes[1].push_back((Note*)new NormalNote(1763));
			this->notes[2].push_back((Note*)new NormalNote(1785));
			this->notes[3].push_back((Note*)new NormalNote(1808));

			this->notes[1].push_back((Note*)new NormalNote(1830));
			this->notes[3].push_back((Note*)new NormalNote(1853));
			this->notes[0].push_back((Note*)new NormalNote(1875));
			this->notes[3].push_back((Note*)new NormalNote(1898));

			this->notes[1].push_back((Note*)new NormalNote(1920));
			this->notes[3].push_back((Note*)new NormalNote(1943));
			this->notes[2].push_back((Note*)new NormalNote(1965));
			this->notes[3].push_back((Note*)new NormalNote(1988));

			this->notes[2].push_back((Note*)new NormalNote(2010));
			this->notes[3].push_back((Note*)new NormalNote(2033));
			this->notes[2].push_back((Note*)new NormalNote(2055));
			this->notes[3].push_back((Note*)new NormalNote(2078));

			this->notes[1].push_back((Note*)new NormalNote(2100));
			this->notes[3].push_back((Note*)new NormalNote(2123));
			this->notes[2].push_back((Note*)new NormalNote(2145));
			this->notes[3].push_back((Note*)new NormalNote(2168));

			this->notes[1].push_back((Note*)new NormalNote(2190));
			this->notes[3].push_back((Note*)new NormalNote(2213));
			this->notes[2].push_back((Note*)new NormalNote(2235));
			this->notes[1].push_back((Note*)new NormalNote(2258));

			this->notes[0].push_back((Note*)new NormalNote(2280));
			this->notes[1].push_back((Note*)new NormalNote(2303));
			this->notes[3].push_back((Note*)new NormalNote(2325));

			this->notes[3].push_back((Note*)new NormalNote(2370));
			this->notes[3].push_back((Note*)new NormalNote(2393));
			this->notes[3].push_back((Note*)new NormalNote(2409));
			this->notes[2].push_back((Note*)new NormalNote(2415));
			this->notes[3].push_back((Note*)new NormalNote(2426));
			this->notes[3].push_back((Note*)new NormalNote(2438));
			this->notes[3].push_back((Note*)new NormalNote(2449));

			this->notes[2].push_back((Note*)new NormalNote(2460));
			this->notes[1].push_back((Note*)new NormalNote(2483));
			this->notes[2].push_back((Note*)new NormalNote(2505));
			this->notes[0].push_back((Note*)new NormalNote(2528));

			this->notes[1].push_back((Note*)new NormalNote(2550));
			this->notes[0].push_back((Note*)new NormalNote(2573));
			this->notes[3].push_back((Note*)new NormalNote(2595));
			this->notes[2].push_back((Note*)new NormalNote(2618));

			this->notes[1].push_back((Note*)new NormalNote(2640));
			this->notes[2].push_back((Note*)new NormalNote(2685));
			this->notes[3].push_back((Note*)new NormalNote(2708));

			this->notes[0].push_back((Note*)new NormalNote(2730));
			this->notes[1].push_back((Note*)new NormalNote(2753));
			this->notes[2].push_back((Note*)new NormalNote(2775));
			this->notes[3].push_back((Note*)new NormalNote(2798));

			this->notes[1].push_back((Note*)new NormalNote(2820));
			this->notes[2].push_back((Note*)new NormalNote(2843));
			this->notes[0].push_back((Note*)new NormalNote(2865));
			this->notes[3].push_back((Note*)new NormalNote(2888));

			this->notes[2].push_back((Note*)new NormalNote(2910));
			this->notes[1].push_back((Note*)new NormalNote(2933));
			this->notes[0].push_back((Note*)new NormalNote(2955));
			this->notes[3].push_back((Note*)new NormalNote(2978));

			this->notes[2].push_back((Note*)new NormalNote(3000));
			this->notes[1].push_back((Note*)new NormalNote(3023));
			this->notes[2].push_back((Note*)new NormalNote(3045));
			this->notes[3].push_back((Note*)new NormalNote(3068));

			this->notes[1].push_back((Note*)new NormalNote(3090));
			this->notes[0].push_back((Note*)new NormalNote(3124));
			this->notes[1].push_back((Note*)new NormalNote(3135));
			this->notes[2].push_back((Note*)new NormalNote(3158));
			this->notes[1].push_back((Note*)new NormalNote(3169));

			this->notes[3].push_back((Note*)new NormalNote(3180));
			this->notes[0].push_back((Note*)new NormalNote(3214));
			this->notes[2].push_back((Note*)new NormalNote(3225));
			this->notes[1].push_back((Note*)new NormalNote(3236));
			this->notes[2].push_back((Note*)new NormalNote(3248));
			this->notes[1].push_back((Note*)new NormalNote(3259));

			this->notes[1].push_back((Note*)new NormalNote(3304));
			this->notes[3].push_back((Note*)new NormalNote(3315));
			this->notes[2].push_back((Note*)new NormalNote(3326));
			this->notes[1].push_back((Note*)new NormalNote(3338));
			this->notes[2].push_back((Note*)new NormalNote(3349));

			this->notes[0].push_back((Note*)new NormalNote(3360));
			this->notes[3].push_back((Note*)new NormalNote(3394));
			this->notes[1].push_back((Note*)new NormalNote(3428));
			this->notes[2].push_back((Note*)new NormalNote(3439));

			this->notes[1].push_back((Note*)new NormalNote(3450));
			this->notes[1].push_back((Note*)new NormalNote(3473));
			this->notes[0].push_back((Note*)new NormalNote(3484));
			this->notes[2].push_back((Note*)new NormalNote(3506));
			this->notes[0].push_back((Note*)new NormalNote(3529));

			this->notes[1].push_back((Note*)new NormalNote(3540));
			this->notes[2].push_back((Note*)new NormalNote(3551));
			this->notes[1].push_back((Note*)new NormalNote(3574));
			this->notes[2].push_back((Note*)new NormalNote(3596));
			this->notes[3].push_back((Note*)new NormalNote(3608));
			this->notes[2].push_back((Note*)new NormalNote(3619));

			this->notes[2].push_back((Note*)new NormalNote(3630));
			this->notes[0].push_back((Note*)new NormalNote(3641));
			this->notes[1].push_back((Note*)new NormalNote(3653));
			this->notes[0].push_back((Note*)new NormalNote(3664));
			this->notes[0].push_back((Note*)new NormalNote(3709));

			this->notes[1].push_back((Note*)new NormalNote(3720));
			this->notes[2].push_back((Note*)new NormalNote(3731));
			this->notes[1].push_back((Note*)new NormalNote(3754));
			this->notes[0].push_back((Note*)new NormalNote(3765));
			this->notes[1].push_back((Note*)new NormalNote(3776));
			this->notes[2].push_back((Note*)new NormalNote(3788));
			this->notes[0].push_back((Note*)new NormalNote(3799));

			this->notes[0].push_back((Note*)new NormalNote(3810));
			this->notes[1].push_back((Note*)new NormalNote(3816));
			this->notes[0].push_back((Note*)new NormalNote(3821));
			this->notes[1].push_back((Note*)new NormalNote(3827));
			this->notes[0].push_back((Note*)new NormalNote(3833));
			this->notes[2].push_back((Note*)new NormalNote(3838));
			this->notes[0].push_back((Note*)new NormalNote(3844));
			this->notes[2].push_back((Note*)new NormalNote(3849));
			this->notes[1].push_back((Note*)new NormalNote(3855));
			this->notes[2].push_back((Note*)new NormalNote(3861));
			this->notes[1].push_back((Note*)new NormalNote(3866));
			this->notes[2].push_back((Note*)new NormalNote(3872));
			this->notes[3].push_back((Note*)new NormalNote(3878));
			this->notes[2].push_back((Note*)new NormalNote(3883));
			this->notes[3].push_back((Note*)new NormalNote(3889));
			this->notes[2].push_back((Note*)new NormalNote(3894));

			this->notes[0].push_back((Note*)new NormalNote(3900));
			this->notes[0].push_back((Note*)new NormalNote(3923));
			this->notes[1].push_back((Note*)new NormalNote(3934));
			this->notes[2].push_back((Note*)new NormalNote(3945));
			this->notes[0].push_back((Note*)new NormalNote(3968));
			this->notes[1].push_back((Note*)new NormalNote(3979));

			this->notes[3].push_back((Note*)new NormalNote(3990));
			this->notes[2].push_back((Note*)new NormalNote(4001));
			this->notes[1].push_back((Note*)new NormalNote(4013));
			this->notes[2].push_back((Note*)new NormalNote(4024));
			this->notes[0].push_back((Note*)new NormalNote(4035));
			this->notes[1].push_back((Note*)new NormalNote(4046));
			this->notes[2].push_back((Note*)new NormalNote(4058));
			this->notes[3].push_back((Note*)new NormalNote(4069));

			this->notes[1].push_back((Note*)new NormalNote(4080));
			this->notes[0].push_back((Note*)new NormalNote(4103));
			this->notes[2].push_back((Note*)new NormalNote(4114));
			this->notes[3].push_back((Note*)new NormalNote(4125));
			this->notes[0].push_back((Note*)new NormalNote(4148));
			this->notes[1].push_back((Note*)new NormalNote(4159));

			this->notes[0].push_back((Note*)new NormalNote(4170));
			this->notes[2].push_back((Note*)new NormalNote(4181));
			this->notes[1].push_back((Note*)new NormalNote(4193));
			this->notes[0].push_back((Note*)new NormalNote(4204));
			this->notes[1].push_back((Note*)new NormalNote(4215));
			this->notes[3].push_back((Note*)new NormalNote(4226));
			this->notes[2].push_back((Note*)new NormalNote(4238));
			this->notes[3].push_back((Note*)new NormalNote(4249));

			this->notes[0].push_back((Note*)new NormalNote(4260));
			this->notes[2].push_back((Note*)new NormalNote(4283));
			this->notes[1].push_back((Note*)new NormalNote(4294));
			this->notes[0].push_back((Note*)new NormalNote(4305));
			this->notes[3].push_back((Note*)new NormalNote(4328));
			this->notes[2].push_back((Note*)new NormalNote(4339));

			this->notes[1].push_back((Note*)new NormalNote(4350));
			this->notes[0].push_back((Note*)new NormalNote(4361));
			this->notes[1].push_back((Note*)new NormalNote(4373));
			this->notes[2].push_back((Note*)new NormalNote(4384));
			this->notes[0].push_back((Note*)new NormalNote(4395));
			this->notes[1].push_back((Note*)new NormalNote(4406));
			this->notes[2].push_back((Note*)new NormalNote(4418));
			this->notes[3].push_back((Note*)new NormalNote(4429));

			this->notes[1].push_back((Note*)new NormalNote(4440));
			this->notes[3].push_back((Note*)new NormalNote(4463));
			this->notes[1].push_back((Note*)new NormalNote(4474));
			this->notes[2].push_back((Note*)new NormalNote(4485));
			this->notes[1].push_back((Note*)new NormalNote(4508));
			this->notes[3].push_back((Note*)new NormalNote(4519));

			this->notes[1].push_back((Note*)new NormalNote(4530));
			this->notes[0].push_back((Note*)new NormalNote(4541));
			this->notes[1].push_back((Note*)new NormalNote(4553));
			this->notes[2].push_back((Note*)new NormalNote(4564));
			this->notes[0].push_back((Note*)new NormalNote(4575));
			this->notes[1].push_back((Note*)new NormalNote(4586));
			this->notes[2].push_back((Note*)new NormalNote(4598));
			this->notes[3].push_back((Note*)new NormalNote(4609));

			this->notes[0].push_back((Note*)new NormalNote(4620));
			this->notes[1].push_back((Note*)new NormalNote(4643));
			this->notes[2].push_back((Note*)new NormalNote(4654));
			this->notes[3].push_back((Note*)new NormalNote(4665));
			this->notes[1].push_back((Note*)new NormalNote(4688));
			this->notes[2].push_back((Note*)new NormalNote(4699));

			this->notes[3].push_back((Note*)new NormalNote(4710));
			this->notes[2].push_back((Note*)new NormalNote(4721));
			this->notes[1].push_back((Note*)new NormalNote(4733));
			this->notes[2].push_back((Note*)new NormalNote(4744));
			this->notes[0].push_back((Note*)new NormalNote(4755));
			this->notes[1].push_back((Note*)new NormalNote(4766));
			this->notes[2].push_back((Note*)new NormalNote(4778));
			this->notes[3].push_back((Note*)new NormalNote(4789));

			this->notes[1].push_back((Note*)new NormalNote(4800));
			this->notes[0].push_back((Note*)new NormalNote(4823));
			this->notes[1].push_back((Note*)new NormalNote(4834));
			this->notes[2].push_back((Note*)new NormalNote(4845));
			this->notes[0].push_back((Note*)new NormalNote(4868));
			this->notes[1].push_back((Note*)new NormalNote(4879));

			this->notes[1].push_back((Note*)new NormalNote(4890));
			this->notes[3].push_back((Note*)new NormalNote(4901));
			this->notes[2].push_back((Note*)new NormalNote(4913));
			this->notes[1].push_back((Note*)new NormalNote(4924));
			this->notes[2].push_back((Note*)new NormalNote(4935));
			this->notes[3].push_back((Note*)new NormalNote(4946));
			this->notes[1].push_back((Note*)new NormalNote(4958));
			this->notes[3].push_back((Note*)new NormalNote(4969));

			this->notes[1].push_back((Note*)new NormalNote(4980));
			this->notes[2].push_back((Note*)new NormalNote(5003));
			this->notes[1].push_back((Note*)new NormalNote(5014));
			this->notes[0].push_back((Note*)new NormalNote(5025));
			this->notes[1].push_back((Note*)new NormalNote(5048));
			this->notes[0].push_back((Note*)new NormalNote(5059));

			this->notes[2].push_back((Note*)new NormalNote(5070));
			this->notes[1].push_back((Note*)new NormalNote(5081));
			this->notes[0].push_back((Note*)new NormalNote(5093));
			this->notes[1].push_back((Note*)new NormalNote(5104));
			this->notes[0].push_back((Note*)new NormalNote(5115));
			this->notes[1].push_back((Note*)new NormalNote(5126));
			this->notes[2].push_back((Note*)new NormalNote(5138));
			this->notes[3].push_back((Note*)new NormalNote(5149));

			this->notes[0].push_back((Note*)new NormalNote(5160));
			this->notes[2].push_back((Note*)new NormalNote(5183));
			this->notes[0].push_back((Note*)new NormalNote(5194));
			this->notes[1].push_back((Note*)new NormalNote(5205));
			this->notes[0].push_back((Note*)new NormalNote(5228));
			this->notes[1].push_back((Note*)new NormalNote(5239));

			this->notes[2].push_back((Note*)new NormalNote(5250));
			this->notes[3].push_back((Note*)new NormalNote(5256));
			this->notes[2].push_back((Note*)new NormalNote(5261));
			this->notes[3].push_back((Note*)new NormalNote(5267));
			this->notes[2].push_back((Note*)new NormalNote(5273));
			this->notes[3].push_back((Note*)new NormalNote(5278));
			this->notes[2].push_back((Note*)new NormalNote(5284));
			this->notes[3].push_back((Note*)new NormalNote(5289));
			this->notes[0].push_back((Note*)new NormalNote(5295));
			this->notes[1].push_back((Note*)new NormalNote(5301));
			this->notes[0].push_back((Note*)new NormalNote(5306));
			this->notes[1].push_back((Note*)new NormalNote(5312));
			this->notes[0].push_back((Note*)new NormalNote(5318));
			this->notes[2].push_back((Note*)new NormalNote(5323));
			this->notes[0].push_back((Note*)new NormalNote(5329));
			this->notes[2].push_back((Note*)new NormalNote(5334));

			this->notes[1].push_back((Note*)new NormalNote(5340));
			this->notes[2].push_back((Note*)new NormalNote(5385));
			this->notes[0].push_back((Note*)new NormalNote(5396));
			this->notes[1].push_back((Note*)new NormalNote(5408));

			this->notes[2].push_back((Note*)new NormalNote(5430));
			this->notes[3].push_back((Note*)new NormalNote(5453));
			this->notes[2].push_back((Note*)new NormalNote(5475));
			this->notes[1].push_back((Note*)new NormalNote(5498));

			this->notes[0].push_back((Note*)new NormalNote(5520));
			this->notes[1].push_back((Note*)new NormalNote(5531));
			this->notes[1].push_back((Note*)new NormalNote(5554));
			this->notes[2].push_back((Note*)new NormalNote(5565));
			this->notes[0].push_back((Note*)new NormalNote(5576));
			this->notes[3].push_back((Note*)new NormalNote(5588));
			this->notes[2].push_back((Note*)new NormalNote(5599));

			this->notes[1].push_back((Note*)new NormalNote(5610));
			this->notes[2].push_back((Note*)new NormalNote(5633));
			this->notes[1].push_back((Note*)new NormalNote(5655));
			this->notes[0].push_back((Note*)new NormalNote(5678));

			this->notes[1].push_back((Note*)new SectionNote(5700, 5728));
			this->notes[0].push_back((Note*)new NormalNote(5745));
			this->notes[1].push_back((Note*)new NormalNote(5756));
			this->notes[2].push_back((Note*)new NormalNote(5768));
			this->notes[3].push_back((Note*)new NormalNote(5779));

			this->notes[3].push_back((Note*)new NormalNote(5801));
			this->notes[2].push_back((Note*)new NormalNote(5813));
			this->notes[3].push_back((Note*)new NormalNote(5824));
			this->notes[1].push_back((Note*)new NormalNote(5835));
			this->notes[3].push_back((Note*)new NormalNote(5846));
			this->notes[2].push_back((Note*)new NormalNote(5858));
			this->notes[3].push_back((Note*)new NormalNote(5869));

			this->notes[1].push_back((Note*)new NormalNote(5880));
			this->notes[3].push_back((Note*)new NormalNote(5891));
			this->notes[2].push_back((Note*)new NormalNote(5903));
			this->notes[3].push_back((Note*)new NormalNote(5914));
			this->notes[1].push_back((Note*)new NormalNote(5925));
			this->notes[3].push_back((Note*)new NormalNote(5936));
			this->notes[2].push_back((Note*)new NormalNote(5948));
			this->notes[3].push_back((Note*)new NormalNote(5959));

			this->notes[2].push_back((Note*)new NormalNote(5970));
			this->notes[1].push_back((Note*)new NormalNote(5981));
			this->notes[0].push_back((Note*)new NormalNote(5993));
			this->notes[2].push_back((Note*)new NormalNote(6004));
			this->notes[3].push_back((Note*)new NormalNote(6026));
			this->notes[2].push_back((Note*)new NormalNote(6038));
			this->notes[3].push_back((Note*)new NormalNote(6049));

			this->notes[2].push_back((Note*)new NormalNote(6060));
			this->notes[1].push_back((Note*)new NormalNote(6071));
			this->notes[0].push_back((Note*)new NormalNote(6083));
			this->notes[0].push_back((Note*)new NormalNote(6094));
			this->notes[1].push_back((Note*)new NormalNote(6105));
			this->notes[3].push_back((Note*)new NormalNote(6128));

			this->notes[2].push_back((Note*)new NormalNote(6150));
			this->notes[3].push_back((Note*)new NormalNote(6173));
			this->notes[1].push_back((Note*)new NormalNote(6195));
			this->notes[0].push_back((Note*)new NormalNote(6218));

			this->notes[1].push_back((Note*)new SectionNote(6240, 6268));
			this->notes[0].push_back((Note*)new NormalNote(6285));
			this->notes[0].push_back((Note*)new NormalNote(6296));
			this->notes[1].push_back((Note*)new NormalNote(6308));

			this->notes[2].push_back((Note*)new NormalNote(6330));
			this->notes[3].push_back((Note*)new NormalNote(6353));
			this->notes[2].push_back((Note*)new NormalNote(6375));
			this->notes[1].push_back((Note*)new NormalNote(6398));

			this->notes[2].push_back((Note*)new NormalNote(6420));
			this->notes[0].push_back((Note*)new NormalNote(6431));
			this->notes[1].push_back((Note*)new NormalNote(6454));
			this->notes[0].push_back((Note*)new NormalNote(6465));
			this->notes[1].push_back((Note*)new NormalNote(6476));
			this->notes[2].push_back((Note*)new NormalNote(6488));
			this->notes[3].push_back((Note*)new NormalNote(6499));

			this->notes[2].push_back((Note*)new NormalNote(6521));
			this->notes[1].push_back((Note*)new NormalNote(6533));
			this->notes[2].push_back((Note*)new NormalNote(6544));
			this->notes[0].push_back((Note*)new NormalNote(6555));
			this->notes[2].push_back((Note*)new NormalNote(6566));
			this->notes[1].push_back((Note*)new NormalNote(6578));
			this->notes[2].push_back((Note*)new NormalNote(6589));

			this->notes[0].push_back((Note*)new NormalNote(6600));
			this->notes[3].push_back((Note*)new NormalNote(6611));
			this->notes[2].push_back((Note*)new NormalNote(6623));
			this->notes[3].push_back((Note*)new NormalNote(6634));
			this->notes[1].push_back((Note*)new NormalNote(6645));
			this->notes[3].push_back((Note*)new NormalNote(6656));
			this->notes[2].push_back((Note*)new NormalNote(6668));
			this->notes[3].push_back((Note*)new NormalNote(6679));

			this->notes[1].push_back((Note*)new NormalNote(6690));
			this->notes[2].push_back((Note*)new NormalNote(6696));
			this->notes[1].push_back((Note*)new NormalNote(6701));
			this->notes[2].push_back((Note*)new NormalNote(6707));
			this->notes[0].push_back((Note*)new NormalNote(6713));
			this->notes[2].push_back((Note*)new NormalNote(6718));
			this->notes[0].push_back((Note*)new NormalNote(6724));
			this->notes[2].push_back((Note*)new NormalNote(6729));
			this->notes[2].push_back((Note*)new NormalNote(6735));
			this->notes[3].push_back((Note*)new NormalNote(6741));
			this->notes[2].push_back((Note*)new NormalNote(6746));
			this->notes[3].push_back((Note*)new NormalNote(6752));
			this->notes[2].push_back((Note*)new NormalNote(6758));
			this->notes[1].push_back((Note*)new NormalNote(6763));
			this->notes[2].push_back((Note*)new NormalNote(6769));
			this->notes[1].push_back((Note*)new NormalNote(6774));

			this->notes[0].push_back((Note*)new SectionNote(6780, 6870));

			// vector 오류 처리용
			this->notes[0].push_back((Note*)new NormalNote(INF));
			this->notes[1].push_back((Note*)new NormalNote(INF));
			this->notes[2].push_back((Note*)new NormalNote(INF));
			this->notes[3].push_back((Note*)new NormalNote(INF));
			break;
		default:
			break;
			
	}
}

void MultiScene::render()
{
	if (this->state == PLAYING) {
		this->renderGame();
	}
	else {
		this->renderInfo();
	}
}

void MultiScene::renderInfo(void)
{
	string content = "";
	
	switch (this->state)
	{
	case CONNECTION_ERR:
		content = "Connection Error!";
		break;
	case CONNECTING_SERVER:
		content = "Connecting Server...";
		break;
	case FINDING_PLAYER:
		content = "Finding Player...";
		break;
	default:
		break;
	}

	glColor3f(1, 1, 1);
	glRasterPos2f(50.f, 50.f);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}


void MultiScene::renderGame()
{
	this->renderNotes();
	this->renderGrid();
	this->renderInputEffect();

	this->renderCombo();
	this->renderJudgement();
	this->renderScoreAndInfo();
}

void MultiScene::renderCombo() {
	float x = 20;
	float y = 50;

	string content = to_string(this->myGameInfo->combo) + " COMBO";
	if (this->myGameInfo->combo > 0) {
		glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(0.04, 0.06, 1);
		glColor4f(1, 0.8f, 0, 0.5f);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.15f, y, 0);
		glColor4f(0, 0.65f, 1, 0.5f);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.3f, y, 0);
		glColor4f(0.19f, 0.65f, 0.32f, 0.5f);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.45f, y, 0);
		glColor4f(0.9f, 1, 0.15f, 0.5f);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
	}

	if (this->opponentGameInfo->combo > 0) {
		x = 85;

		content = to_string(this->opponentGameInfo->combo) + " COMBO";

		glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(0.04, 0.06, 1);
		glColor4f(1, 0.8f, 0, 0.5f);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.15f, y, 0);
		glColor4f(0, 0.65f, 1, 0.5f);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.3f, y, 0);
		glColor4f(0.19f, 0.65f, 0.32f, 0.5f);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.45f, y, 0);
		glColor4f(0.9f, 1, 0.15f, 0.5f);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
	}
}

void MultiScene::renderJudgement()
{
	float x = 20;
	float y = 36;

	string content = "";
	if (this->myGameInfo->recentJudgement != NONE) {

		switch (this->myGameInfo->recentJudgement) {
		case PERFECT:
			glColor4f(0.64f, 0.05f, 0.6f, 0.5f);
			content = "PERFECT";
			break;
		case GREAT:
			glColor4f(0.9f, 0.55f, 0.15f, 0.5f);
			content = " GREAT ";
			break;
		case NORMAL:
			glColor4f(0.1f, 0.75f, 0.15f, 0.5f);
			content = " NORMAL";
			break;
		case BAD:
			glColor4f(0.3f, 0.75f, 0.74f, 0.5f);
			content = "  BAD  ";
			break;
		case MISS:
			glColor4f(0.4f, 0.4f, 0.4f, 0.5f);
			content = "  MISS  ";
			break;
		}


		glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.15f, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.3f, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.45f, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
	}

	if (this->opponentGameInfo->recentJudgement != NONE) {
		x = 85;
		content = "";
		switch (this->opponentGameInfo->recentJudgement) {
		case PERFECT:
			glColor4f(0.64f, 0.05f, 0.6f, 0.5f);
			content = "PERFECT";
			break;
		case GREAT:
			glColor4f(0.9f, 0.55f, 0.15f, 0.5f);
			content = " GREAT ";
			break;
		case NORMAL:
			glColor4f(0.1f, 0.75f, 0.15f, 0.5f);
			content = " NORMAL";
			break;
		case BAD:
			glColor4f(0.3f, 0.75f, 0.74f, 0.5f);
			content = "  BAD  ";
			break;
		case MISS:
			glColor4f(0.4f, 0.4f, 0.4f, 0.5f);
			content = "  MISS  ";
			break;
		}


		glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.15f, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.3f, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
		glPushMatrix();
		glTranslatef(x + 0.45f, y, 0);
		glScalef(0.04, 0.06, 1);
		glLineWidth(5);
		for (auto c : content)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
		}
		glPopMatrix();
	}
}

void MultiScene::renderScoreAndInfo()
{
	float x = 30;
	float y = 105;

	string content = "Score: " + to_string(this->myGameInfo->score);
	glColor4f(1, 1, 1, 1);
	glRasterPos2f(x, y);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	x = 95;
	content = "Score: " + to_string(this->opponentGameInfo->score);
	glColor4f(1, 1, 1, 1);
	glRasterPos2f(x, y);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}

void MultiScene::renderInputEffect() {
	for (int i = 0;i < LINES;i++) {
		if (!this->renderKey[i]) continue;
		
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex2f(P1_COLUMN + (i * 4), 5);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P1_COLUMN + (i * 4), 40.f);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P1_COLUMN + 4 + (i * 4), 40.f);
		glColor3f(1, 1, 1);
		glVertex2f(P1_COLUMN + 4 + (i * 4), 5);
		glEnd();
	}

	for (int i = 0;i < LINES;i++) {
		if (!this->opponentRenderKey[i]) continue;

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex2f(P2_COLUMN + (i * 4), 5);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P2_COLUMN + (i * 4), 40.f);
		glColor4f(0, 0, 0, 0);
		glVertex2f(P2_COLUMN + 4 + (i * 4), 40.f);
		glColor3f(1, 1, 1);
		glVertex2f(P2_COLUMN + 4 + (i * 4), 5);
		glEnd();
	}
}

void MultiScene::renderGrid()
{
	glLineWidth(1);
	glColor3f(1, 1, 1);

	// 내 그리드
	for (int i = 0; i < LINES + 1; ++i) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(P1_COLUMN + (i * 4), 0);
		glVertex2f(P1_COLUMN + (i * 4), ROWS);
		glEnd();
	}
	

	// 상대 그리드
	for (int i = 0; i < LINES + 1; ++i) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(P2_COLUMN + (i * 4), 0);
		glVertex2f(P2_COLUMN + (i * 4), ROWS);
		glEnd();
	}

	glColor3f(1, 1, 1);
	glRectd(P1_COLUMN, 5, P1_COLUMN + (4 * LINES), 6);
	glRectd(P2_COLUMN, 5, P2_COLUMN + (4 * LINES), 6);
	
	// 가운데 대결모양
	// HSV 색 모델 이용
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(63.5f, -30);
	glVertex2f(61, 58);
	glVertex2f(63.5f, 55);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(63.5f, ROWS+30);
	glVertex2f(66, 50);
	glVertex2f(63.5f, 53);
	glEnd();
}

void MultiScene::renderNotes(void)
{
	if (frame + 120 > 10000) return;
	int input_count = 0;
	for (int line = 0; line < LINES; ++line) {
		for (int scope = 0; scope < this->notes[line].size(); ++scope) {
			if (this->notes[line][scope] == nullptr)
				break;
			//cout << "fps: " << frame << " | ";
			if (this->notes[line][scope]->IsActive(frame) && this->notes[line][scope]->isAlive) {
				// 노트의 색 지정
				switch (line)
				{
				case 0:
					glColor3f(1, 0.8f, 0);
					break;
				case 1:
					glColor3f(0, 0.65f, 1);
					break;
				case 2:
					glColor3f(0.19f, 0.65f, 0.32f);
					break;
				case 3:
					glColor3f(0.9f, 1, 0.15f);
				default:
					break;
				}

				// 바닥으로부터 노트(바닥)까지의 거리
				int height = this->notes[line][scope]->GetHeight(frame);
				int noteLength = this->notes[line][scope]->getNoteLength();

				// 롱노트에 대하여
				if (this->notes[line][scope]->type == 1) {
					int bottom = 0;
					// 롱노트가 현재 입력 대기중인 노트이고, 그 노트가 입력중일 때
					if (scope == line_input[line] && section_judgement[line] != -1) {
						bottom = JUDGE_HEIGHT;
					}

					// 일부 롱노트가 화면 아래에 있음
					if (height < 2) {
						glRectd(P1_COLUMN + ((float)line * 4), bottom, (P1_COLUMN + 4) + ((float)line * 4), height + noteLength);
						glRectd(P2_COLUMN + ((float)line * 4), bottom, (P2_COLUMN + 4) + ((float)line * 4), height + noteLength);
					}
					else {
						glRectd(P1_COLUMN + ((float)line * 4), height, (P1_COLUMN + 4) + ((float)line * 4), height + noteLength);
						glRectd(P2_COLUMN + ((float)line * 4), height, (P2_COLUMN + 4) + ((float)line * 4), height + noteLength);
					}
				}
				else {
					glRectd(P1_COLUMN + ((float)line * 4), height, (P1_COLUMN + 4) + ((float)line * 4), height + noteLength);
					glRectd(P2_COLUMN + ((float)line * 4), height, (P2_COLUMN + 4) + ((float)line * 4), height + noteLength);
				}

				//}
				//cout << frame << " | " << line << ":" << height << "\n";

				if (line == 0 && (0 <= height && height <= 10)) {
					//	cout << line << ":" << height << "\n";
				}
			}
		}
	}
}

void MultiScene::update()
{
	if (this->state == PLAYING) {
		if (this->frame == START_FRAME) {
			this->playSound();
		}

		++this->frame;

		// 입력 검사
		this->checkInput();
		this->checkSectionNote();
		this->deleteMissNode();

		// frame 싱크 조절
		calcSync();
		syncTimer();
		if (frame == endFrame) {
			isEnd = true;
		}
		if (this->isEnd) {
			BASS_Free();
			this->window->scene = new ResultScene(this->window, myGameInfo, opponentGameInfo, 1);
			free(this->myGameInfo);
			free(this->opponentGameInfo);
			free(this->U_Config);
			delete(this);
		}
	}
}
	

void MultiScene::setInput(unsigned char key)
{
	if (key == 'd') {
		this->key[0] = true;
		this->renderKey[0] = true;
		this->playEffectSound();
		
		gameSocket->sendInput(0);
	}
	else if (key == 'f') {
		this->key[1] = true;
		this->renderKey[1] = true;
		this->playEffectSound();

		gameSocket->sendInput(1);
	}
	else if (key == 'j') {
		this->key[2] = true;
		this->renderKey[2] = true;
		this->playEffectSound();

		gameSocket->sendInput(2);
	}
	else if (key == 'k') {
		this->key[3] = true;
		this->renderKey[3] = true;
		this->playEffectSound();

		gameSocket->sendInput(3);
	}
	else if (key == '[') {
		U_Config->M_Vol -= 0.1;
		if (U_Config->M_Vol < 0) U_Config->M_Vol = 0;
		setMVol(U_Config->M_Vol);
	}
	else if (key == ']') {
		U_Config->M_Vol += 0.1;
		if (U_Config->M_Vol > 1) U_Config->M_Vol = 1;
		setMVol(U_Config->M_Vol);
	}
	//효과음 볼륨조정
	else if (key == ',') {
		U_Config->E_Vol -= 0.1;
		printf("%f\n", U_Config->E_Vol);
		if (U_Config->E_Vol < 0) U_Config->E_Vol = 0;
	}
	else if (key == '.') {
		U_Config->E_Vol += 0.1;
		if (U_Config->E_Vol > 1) U_Config->E_Vol = 1;
	}
}

void MultiScene::unsetInput(unsigned char key)
{
	if (key == 'd') {
		this->key[0] = false;
		this->renderKey[0] = false;

		gameSocket->sendUnput(0);
	}
	else if (key == 'f') {
		this->key[1] = false;
		this->renderKey[1] = false;

		gameSocket->sendUnput(1);
	}
	else if (key == 'j') {
		this->key[2] = false;
		this->renderKey[2] = false;

		gameSocket->sendUnput(2);
	}
	else if (key == 'k') {
		this->key[3] = false;
		this->renderKey[3] = false;

		gameSocket->sendUnput(3);
	}
}

void MultiScene::getNoteDelay(int line, unsigned int i_frame)
{
	int n_frame = this->line_input[line];
	Note* nott = this->notes[line][n_frame];

	float n_delay = nott->GetHeight(i_frame) - JUDGE_HEIGHT;
	int noteType = nott->type;
	int judgeType = 5;

	// 일정 범위 내에 노트가 존재함
	if (n_delay <= MISS_FRAME) {

		//노트 판정
		if (n_delay <= PERFECT_FRAME && n_delay >= -(PERFECT_FRAME / 2)) {
			judgeType = 1;
		}
		else if (n_delay <= GREAT_FRAME && n_delay >= -(GREAT_FRAME / 2)) {
			judgeType = 2;
		}
		else if (n_delay <= NORMAL_FRAME && n_delay >= -(NORMAL_FRAME/2)) {
			judgeType = 3;
		}
		else if (n_delay <= BAD_FRAME && n_delay >= -(BAD_FRAME/2)) {
			judgeType = 4;
		}

		/*이 부분 함수 만들어주시면 됩니다!!*/
		 receiveJudgement(judgeType, nott);

		// 롱노트
		if (noteType == 1) {
			section_judgement[line] = judgeType;
			section_delay[line] = n_delay;
			section_input[line] = 1;
		}
		// 이외의 노트
		else {
			// 노트 지움
			this->deleteNote(line, n_frame);
			this->setLineInput(line);
		}
	}

}

void MultiScene::deleteNote(int line, int n_frame)
{
	if (this->notes[line][n_frame] != nullptr) {
		this->notes[line][n_frame]->killNote();
	}

}

void MultiScene::deleteMissNode()
{
	for (int i = 0; i < LINES; i++) {
		if (this->notes[i][line_input[i]]->IsMissNote(frame)) {
			Note* nott = this->notes[i][line_input[i]];
			/*이 부분 함수 만들어주시면 됩니다!!*/
			receiveJudgement(6, nott);
			this->notes[i][line_input[i]]->killNote();
			this->setLineInput(i);
		}
	}

}

int MultiScene::getLineInput(int line)
{
	return this->line_input[line];
}

void MultiScene::setLineInput(int line)
{
	this->line_input[line]++;
}

void MultiScene::receiveJudgement(int judge, Note* nott)
{
	//(0 = Normal, 1 = Section, 2 = Lie, 3 = LieSection 4 = 하이라이트 5 = Item1, 6 = Item2, 7 = Item3)

	int type = nott->type;

	//miss 아닐때만 확인
	//item1 : 회복, 2판정, up 3상대방 가리기 

	if (type >= 5 && judge < 5) {


		if (type == 5) {
			myGameInfo->HP += 30;
		}
		else if (type == 6) {
			//프레임 단위(임시)
			reinforce += 1000;
		}
	}

	//판정 up 아이템 적용
	//퍼펙트 < 해당노트 < miss 해당노트 판정 up
	if (reinforce > 0 && judge > 1 && judge < 5) {
		judge--;
	}
	//lie노트
	//놓쳤을 때가 아닐 때 처리

	// 가짜 노트 - 수정 필수!!!!!!!!!!!!! 가짜 롱노트 부분
	if (type == 2) {
		printf("lie\n");
		if (judge < 6)
			myGameInfo->HP -= 30;
	}
	else if (type == 1) {
		calcSectionInfo(judge);
	}
	else if (type == 4)
		calcInfo(judge, 1);
	else calcInfo(judge, 0);

	if (myGameInfo->HP > 100)
		myGameInfo->HP = 100;

	gameSocket->sendNote(judge, this->myGameInfo->score, this->myGameInfo->combo);

	if (myGameInfo->HP <= 0) {
		/*사망 조건 필수!!!!!!*/
		//this->isEnd = true;
	}

}

void MultiScene::calcInfo(int judge, int highlight)
{
	//perfect 1 great 2 normal 3 bad 4 miss : 점수 계산 없음
//노트 점수 : 기본점수 * 콤보 보너스(100combo당 10% 증가) * 판정 점수(1.3 1.1 1.0 0.5 0)
	int base = 0;
	if (highlight)
		base = 150;
	else
		base = 100;

	int interval = myGameInfo->combo / 100;
	float calc = 0;

	switch (judge) {
	case 1:
		myGameInfo->HP += 2;
		myGameInfo->combo++;
		myGameInfo->perfect++;
		myGameInfo->recentJudgement = PERFECT;
		calc = base * (1 + (interval * 0.1)) * 1.3;
		break;
	case 2:
		myGameInfo->HP += 1;
		myGameInfo->combo++;
		myGameInfo->great++;
		myGameInfo->recentJudgement = GREAT;
		calc = base * (1 + (interval * 0.1)) * 1.1;
		break;
	case 3:
		myGameInfo->combo++;
		myGameInfo->normal++;
		myGameInfo->recentJudgement = NORMAL;
		calc = base * (1 + (interval * 0.1)) * 1;
		break;
	case 4:
		myGameInfo->HP -= 5;
		myGameInfo->combo = 0;
		myGameInfo->bad++;
		myGameInfo->recentJudgement = BAD;
		calc = base * 0.5;
		break;
	default:
		myGameInfo->HP -= 10;
		myGameInfo->combo = 0;
		myGameInfo->miss++;
		myGameInfo->recentJudgement = MISS;
	}
	if (myGameInfo->max_combo < myGameInfo->combo) {
		myGameInfo->max_combo = myGameInfo->combo;
	}
	int tmp = calc;
	myGameInfo->score += tmp;

}

void MultiScene::checkSectionNote()
{
	for (int i = 0; i < LINES; i++) {
		if (section_judgement[i] != -1) {
			Note* current_section = notes[i][line_input[i]];
			if (this->renderKey[i]) {
				if (current_section->getNoteLength() > section_input[i]) {
					/*이 부분 함수 만들어주시면 됩니다!!*/
					receiveJudgement(section_judgement[i], current_section);

					section_input[i] += 1;
				}
				else if (current_section->getNoteLength() == section_input[i]) {
					section_input[i] = 0;
					section_judgement[i] = -1;
					section_delay[i] = 0;

					this->deleteNote(i, line_input[i]);
					this->setLineInput(i);
				}
			}
			else {
				unsigned int end_frame =
					(current_section->createFrame + current_section->getNoteLength()) + (ROWS - JUDGE_HEIGHT);
				unsigned int unset_delay = end_frame - frame;

				this->deleteNote(i, line_input[i]);
				this->setLineInput(i);

				if (unset_delay <= NORMAL_FRAME && unset_delay >= -NORMAL_FRAME) {
					/*이 부분 함수 만들어주시면 됩니다!!*/
					receiveJudgement(section_judgement[i], current_section);
				}
				else {
					/*이 부분 함수 만들어주시면 됩니다!!*/
					receiveJudgement(5, current_section);
				}

				section_input[i] = 0;
				section_judgement[i] = -1;
				section_delay[i] = 0;
			}

		}
		else {
			continue;
		}

	}

}

void MultiScene::calcSectionInfo(int judge)
{
	//perfect 1 great 2 normal 3 bad 4 miss : 점수 계산 없음
//노트 점수 : 기본점수 * 콤보 보너스(100combo당 10% 증가) * 판정 점수(1.3 1.1 1.0 0.5 0)
	int base = 100;
	int interval = myGameInfo->combo / 100;
	float calc = 0;

	switch (judge) {
	case 1:
		myGameInfo->HP += 0.2;
		myGameInfo->combo++;
		myGameInfo->perfect++;
		myGameInfo->recentJudgement = PERFECT;
		calc = base * (1 + (interval * 0.1)) * 1.3;
		break;
	case 2:
		myGameInfo->HP += 0.1;
		myGameInfo->combo++;
		myGameInfo->great++;
		myGameInfo->recentJudgement = GREAT;
		calc = base * (1 + (interval * 0.1)) * 1.1;
		break;
	case 3:
		myGameInfo->combo++;
		myGameInfo->normal++;
		myGameInfo->recentJudgement = NORMAL;
		calc = base * (1 + (interval * 0.1)) * 1;
		break;
	case 4:
		myGameInfo->HP -= 0.5;
		myGameInfo->combo = 0;
		myGameInfo->bad++;
		myGameInfo->recentJudgement = BAD;
		calc = base * 0.5;
		break;
	default:
		myGameInfo->HP -= 10;
		myGameInfo->combo = 0;
		myGameInfo->miss++;
		myGameInfo->recentJudgement = MISS;
	}

	int tmp = calc;
	myGameInfo->score += tmp;

}

void MultiScene::checkInput()
{
	while (!InputQueue.empty()) {
		// 현재 입력
		Input* current_input = InputQueue.front();

		int i_line = current_input->getInputLine();
		unsigned int i_frame = current_input->getInputFrame();

		// 입력 처리
		getNoteDelay(i_line, i_frame);

		// Queue 제거
		InputQueue.pop();
		delete current_input;
	}

}

void MultiScene::addInput(int key)
{
	InputQueue.push(new Input(frame, key));

}

void MultiScene::calcSync()
{
	if (init_timer == NULL) {
		init_timer = clock();
	}
	clock_t passed_time = clock() - init_timer;
	clock_delay = double(passed_time) - round(16.667 * frame);


}

void MultiScene::syncTimer()
{
	if (frame % 30 == 0) {
		setSync();
	}
}

void MultiScene::setSync()
{
	if (clock_delay < 0) {
		Sleep(-double(clock_delay));
	}
}

void MultiScene::loadMusic()
{
	this->stream = BASS_StreamCreateFile(FALSE, this->musicFile.c_str(), 0, 0, 0);
	BASS_ChannelPlay(this->stream, FALSE);
	setMVol(U_Config->M_Vol);
	BASS_ChannelPause(this->stream);

	//끝나는 시점 계산
	QWORD len = BASS_ChannelGetLength(stream, BASS_POS_BYTE);
	double time = BASS_ChannelBytes2Seconds(stream, len);
	endFrame = START_FRAME + (time * FPS);
}

void MultiScene::playSound()
{
	if (this->stream) {
		BASS_ChannelPlay(this->stream, FALSE);
	}
}

void MultiScene::playEffectSound()
{
	HSTREAM effect = BASS_StreamCreateFile(FALSE, "./hit_sound.mp3", 0, 0, 0);
	BASS_ChannelSetAttribute(effect, BASS_ATTRIB_VOL, U_Config->E_Vol);
	BASS_ChannelPlay(effect, FALSE);
}

void MultiScene::setMVol(float volume)
{
	bool check = BASS_ChannelSetAttribute(stream, BASS_ATTRIB_VOL, volume);
}
