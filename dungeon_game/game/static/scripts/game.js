const DungeonGame = {
    elements: {
        dungeonGrid: document.getElementById('dungeon-grid'),
        minhealth: document.getElementById('minhealth'),
        newGameBtn: document.getElementById('new-game-btn'),
        cellLegend: document.getElementById('cell-legend'),
        dungeonrows: document.getElementById('dungeon-rows'),
        dungeoncols: document.getElementById('dungeon-cols'),
    },

    init() {
        this.elements.newGameBtn.addEventListener('click', () => {
            console.log('Generate Dungeon button clicked'); // Debugging
            this.generateDungeon();
        });
        this.generateDungeon(); 
    },

    generateDungeon() {
        const rows = parseInt(this.elements.dungeonrows.value, 10);
        const cols = parseInt(this.elements.dungeoncols.value, 10);
        console.log(rows)
        console.log(cols)
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
        // Set grid columns dynamically
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
        return axios.post('/calculate-minimum-health/', { dungeon }, {
            headers: { 'X-CSRFToken': document.querySelector('[name=csrf-token]').content }
        })
        .then(healthResponse => {
            this.elements.minhealth.textContent = healthResponse.data.minimum_health;
        })
        .catch(this.handleError);
    },
    handleError(error) {
        console.error('Dungeon generation error:', error);
        this.elements.minhealth.textContent = 'Error';
    },
};
DungeonGame.init();