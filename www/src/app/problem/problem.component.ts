import { Component, OnInit } from '@angular/core';
import { Problem } from '../../../src/model/Problem';
import { ProblemService } from '../problem.service';
import { AngularFirestore } from '@angular/fire/firestore';

@Component({
  selector: 'app-problem',
  templateUrl: './problem.component.html',
  styleUrls: ['./problem.component.scss'],
})
export class ProblemComponent implements OnInit {
  problem: Problem;

  constructor(private db: AngularFirestore, private problemService: ProblemService) {}

  ngOnInit() {
    this.problemService.getProblem().subscribe((p: Problem) => (this.problem = p));
  }
  onDelete() {
    this.db
      .collection('problem')
      .doc(this.problem.id)
      .delete();

    this.db
      .collection('trashbin')
      .doc(this.problem.id)
      .set(this.problem.parse());
  }
}
