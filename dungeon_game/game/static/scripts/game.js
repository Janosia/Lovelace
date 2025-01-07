const DungeonGame = {
    elements: {
        dungeonGrid: document.getElementById('dungeon-grid'),
        minhealth: document.getElementById('minhealth'),
        new_game_btn: document.getElementById('new-game-btn'),
        dungeonrows: document.getElementById('dungeon-rows'),
        dungeoncols: document.getElementById('dungeon-cols'),
        gen_dungeon_btn: document.getElementById('generate-dungeon-btn'),
        guess: document.getElementById("user-guess"),
        show_result_btn: document.getElementById("accept"),
    },

    init() {
        this.elements.gen_dungeon_btn.addEventListener('click', () =>{
            this.generateDungeon();
        });
        this.elements.new_game_btn.addEventListener('click', () => {
            this.generateDungeon();
        });
        this.elements.show_result_btn.addEventListener('click', () => {
            console.log("Result button pressed");
            this.results()
        });
    },

    generateDungeon() {
        const rows = parseInt(this.elements.dungeonrows.value, 10);
        const cols = parseInt(this.elements.dungeoncols.value, 10);
        if (isNaN(rows) || isNaN(cols) || rows < 1 || cols < 1) {
            alert('Please enter valid row and column values!');
            return;
        }
        axios.get(`/generate-dungeon/?rows=${rows}&cols=${cols}`)
        .then(response => {
            this.renderDungeon(response.data);
            return response.data;
            
        })
        .then(data=> {
            this.calculateHealth(data.dungeon)
        })
        .catch(this.handleError);
    },
    renderDungeon({ dungeon_details, rows, cols }) {
        this.elements.dungeonGrid.style.gridTemplateColumns = `repeat(${cols}, 1fr)`;
        this.elements.dungeonGrid.innerHTML = '';
        dungeon_details.forEach(row => row.forEach(this.createCell.bind(this)));
    },
    createCell(cellData) {
        const cellElement = document.createElement('div');
        cellElement.classList.add('cell-item', 'border', 'rounded', 'overflow-hidden', 'shadow-lg');
        const img = document.createElement('img');
        img.src = `/static/image/${cellData.image}`;
        img.alt = cellData.type;
        img.classList.add('cell-image');
        cellElement.appendChild(img);
        const damageSpan = document.createElement('span');
        damageSpan.textContent = cellData.damage;
        damageSpan.classList.add('cell-damage');
        cellElement.appendChild(damageSpan);
        this.elements.dungeonGrid.appendChild(cellElement);
    },

    calculateHealth(dungeon) {
        const val=0;
        guess_user = parseInt(this.elements.guess.value, 10); 
        return axios.post('/calculate-minimum-health/', { dungeon ,guess_user }, {
            headers: { 'X-CSRFToken': document.querySelector('[name=csrf-token]').content }
        })
        .then(healthResponse => {
            console.log(healthResponse.data.minimum_health);
            this.elements.minhealth.textContent = healthResponse.data.minimum_health;
            return healthResponse.data.minimum_health;
        })
        .catch(this.handleError);
    },
    handleError(error) {
        console.error('Dungeon generation error:', error);
        this.elements.minhealth.textContent = 'Error';
    },
    results(){
        console.log("wewoo");
        this.calculateHealth(dungeon).then(comp => {
            console.log('Calculated minimum health:', comp);
        }).catch(error => {
            console.error('Error in calculating minimum health:', error);
        });
    }
};
DungeonGame.init();